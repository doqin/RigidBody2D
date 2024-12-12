//
// Created by đỗ quyên on 12/12/24.
//

#include "TestStage.h"

#include <iostream>

#include "component/BoxCollider2D.h"
#include "component/PlayerController.h"
#include "screen/GameplayScreen.h"

TestStage::TestStage(GameplayScreen *gameScreen): e(), stageWidth(0), stageHeight(0) {
    this->gameScreen = gameScreen;
}

void TestStage::Init() {
    // Set stage size
    stageWidth = 1200;
    stageHeight = 1200;

    // Create player gameObject
    auto* player = new GameObject();
    player->x = gameScreen->viewPort.w / 2.0;
    player->y = gameScreen->viewPort.h / 2.0;
    gameObjects.push_back(player);
    // Create player
    auto* playerSprite = new Sprite();
    playerSprite->loadFromFile(gameScreen->game->renderer, "../assets/player.png");
    SDL_Rect* playerCollider = new SDL_Rect();
    playerCollider->x = static_cast<int>(player->x);
    playerCollider->y = static_cast<int>(player->y);
    playerCollider->w = 50;
    playerCollider->h = 50;
    sprites.push_back(new ScreenRepresentation(player, playerSprite));
    controllers.push_back(new PlayerController(player, 0.5));
    rigidBodies.push_back(new RigidBody2D(player));
    colliders.push_back(new BoxCollider2D(player, playerCollider));

    // Ground gameObject
    auto* ground = new GameObject();
    ground->x = gameScreen->viewPort.w / 2.0;
    ground->y = gameScreen->viewPort.h;
    ground->xDir = 0;
    ground->yDir = 0;
    gameObjects.push_back(ground);
    SDL_Rect* groundCollider = new SDL_Rect();
    groundCollider->x = static_cast<int>(ground->x);
    groundCollider->y = static_cast<int>(ground->y);
    groundCollider->w = gameScreen->viewPort.w;
    groundCollider->h = 50;
    colliders.push_back(new BoxCollider2D(ground, groundCollider));
}

void TestStage::Cleanup() {
    for (GameObject* gameObject : gameObjects) {
        delete gameObject;
    }
    for (ScreenRepresentation* sprite : sprites) {
        sprite->sprite->free();
        delete sprite;
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
            controller->HandleEvents(e);
        }
    }
}

void TestStage::Update() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();
    deltaTime = (NOW - LAST) * 1000.0 / static_cast<double>(SDL_GetPerformanceFrequency());
    for (PlayerController* controller : controllers) {
        controller->Update(deltaTime);
    }
    for (RigidBody2D* rigidBody : rigidBodies) {
        rigidBody->Update(deltaTime);
    }
    for (BoxCollider2D* collider : colliders) {
        collider->Update(colliders, deltaTime);
    }
}

void TestStage::Draw() {
    // Clear screen
    SDL_SetRenderDrawColor(gameScreen->game->renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(gameScreen->game->renderer);

    for (ScreenRepresentation* sprite : sprites) {
        sprite->sprite->render(gameScreen->game->renderer, sprite->gameObject->x - sprite->sprite->getWidth() / 4.0, sprite->gameObject->y - sprite->sprite->getHeight() / 4.0, sprite->sprite->getWidth() / 2.0, sprite->sprite->getHeight() / 2.0);
    }

    // Update screen
    SDL_RenderPresent(gameScreen->game->renderer);
}
