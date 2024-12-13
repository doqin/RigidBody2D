//
// Created by đỗ quyên on 12/12/24.
//

#include "TestStage.h"

#include <iostream>

#include "component/BoundaryCollider2D.h"
#include "component/BoxCollider2D.h"
#include "component/PlayerController.h"
#include "component/Vector2D.h"
#include "screen/GameplayScreen.h"

TestStage::TestStage(GameplayScreen *gameScreen): e(), stageWidth(0), stageHeight(0) {
    this->gameScreen = gameScreen;
}

void TestStage::Init() {
    // Set stage size
    stageWidth = 1200;
    stageHeight = 1200;

    // Create player gameObject
    auto player = new GameObject(gameScreen->viewPort.w / 2.0, gameScreen->viewPort.h / 2.0);
    gameObjects.push_back(player);
    auto* playerSprite = new Sprite();
    playerSprite->loadFromFile(gameScreen->game->renderer, "../assets/player.png");
    auto* playerCollider2D = new BoxCollider2D(player, static_cast<int>(player->x), static_cast<int>(player->y), playerSprite->getWidth() / 2.0, playerSprite->getHeight() / 2.0);
    sprites.push_back(new ScreenRepresentation(player, playerSprite));
    auto* playerRigidBody2D = new RigidBody2D(player, playerCollider2D);
    controllers.push_back(new PlayerController(player, playerRigidBody2D, playerCollider2D, 0.5));
    rigidBodies.push_back(playerRigidBody2D);
    colliders.push_back(playerCollider2D);

    // Left wall gameObject
    auto *leftWall = new GameObject(0, gameScreen->viewPort.h / 2.0);
    gameObjects.push_back(leftWall);
    auto* leftWallCollider2D = new BoxCollider2D(leftWall, static_cast<int>(leftWall->x), static_cast<int>(leftWall->y), 50, gameScreen->viewPort.h);
    colliders.push_back(leftWallCollider2D);

    // Bottom boundary
    auto* bottomBoundary = new BoundaryCollider2D(0, gameScreen->viewPort.h - 100, Vector2D(0.1, -1));
    boundaries.push_back(bottomBoundary);
}

void TestStage::Cleanup() {
    for (GameObject* gameObject : gameObjects) {
        delete gameObject;
    }
    for (ScreenRepresentation* sprite : sprites) {
        sprite->sprite->free();
        delete sprite;
    }
    for (PlayerController* controller : controllers) {
        delete controller;
    }
    for (RigidBody2D* rigidBody : rigidBodies) {
        delete rigidBody;
    }
    for (BoxCollider2D* collider : colliders) {
        delete collider;
    }
    for (BoundaryCollider2D* boundary : boundaries) {
        delete boundary;
    }
}

void TestStage::Pause() {
}

void TestStage::Resume() {
}

void TestStage::HandleEvents() {
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                gameScreen->game->Quit();
                break;
            default:
                break;
        }
        for (PlayerController* controller : controllers) {
            controller->HandleEvents(e, controller->rigidBody);
        }
    }
}

void TestStage::Update() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    deltaTime = (NOW - LAST) * 1000.0 / static_cast<double>(SDL_GetPerformanceFrequency());

    // Update rigid bodies and check collision
    for (RigidBody2D* rigidBody : rigidBodies) {
        rigidBody->Update(boundaries, deltaTime);
    }
    // Update colliders after rigid bodies
    for (BoxCollider2D* collider : colliders) {
        collider->Update();
    }
    // Update player movement
    for (PlayerController* controller : controllers) {
        controller->Update(colliders, deltaTime);
    }
    // Update colliders
    for (BoxCollider2D* collider : colliders) {
        collider->Update();
    }
    if (gameScreen->frameDelay > deltaTime) {
        SDL_Delay(static_cast<Uint32>(gameScreen->frameDelay - deltaTime));
    }
}

void TestStage::Draw() {
    // Clear screen
    SDL_SetRenderDrawColor(gameScreen->game->renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(gameScreen->game->renderer);
    // Draw sprites
    for (ScreenRepresentation* sprite : sprites) {
        sprite->sprite->render(gameScreen->game->renderer, sprite->gameObject->x - sprite->sprite->getWidth() / 4.0, sprite->gameObject->y - sprite->sprite->getHeight() / 4.0, sprite->sprite->getWidth() / 2.0, sprite->sprite->getHeight() / 2.0);
    }
    // Draw box colliders
    SDL_SetRenderDrawColor(gameScreen->game->renderer, 0xFF, 0, 0, 0xFF);
    for (BoxCollider2D* collider : colliders) {
        SDL_RenderDrawRect(gameScreen->game->renderer, collider->boxCollider);
    }
    // Draw boundaries
    SDL_SetRenderDrawColor(gameScreen->game->renderer, 0, 0xFF, 0, 0xFF);
    for (BoundaryCollider2D* boundary : boundaries) {
        boundary->DrawCollider(gameScreen->game->renderer, gameScreen->viewPort.x, gameScreen->viewPort.w);
    }
    // Update screen
    SDL_RenderPresent(gameScreen->game->renderer);
}
