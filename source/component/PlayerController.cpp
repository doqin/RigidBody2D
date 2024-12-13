//
// Created by đỗ quyên on 12/12/24.
//

#include "PlayerController.h"

#include <iostream>

#include "BoundaryCollider2D.h"
#include "BoxCollider2D.h"
#include "GameObject.h"

void PlayerController::HandleEvents(const SDL_Event &e) {
    switch (e.type) {
        case SDL_KEYDOWN:
            if (e.key.repeat == 0)
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        xDir -= 1.0;
                        break;
                    case SDLK_RIGHT:
                        xDir += 1.0;
                        break;
                    default:
                        break;
                }
            break;
        case SDL_KEYUP:
            if (e.key.repeat == 0)
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        xDir += 1.0;
                        break;
                    case SDLK_RIGHT:
                        xDir -= 1.0;
                        break;
                    default:
                        break;
                }
        default:
            break;
    }
}

void PlayerController::HandleEvents(const SDL_Event &e, RigidBody2D *rigidBody) {
    switch (e.type) {
        case SDL_KEYDOWN:
            if (e.key.repeat == 0)
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        xDir -= 1.0;
                        break;
                    case SDLK_RIGHT:
                        xDir += 1.0;
                        break;
                    case SDLK_UP:
                        rigidBody->jumpForce = -0.5;
                        break;
                    default:
                        break;
                }
        break;
        case SDL_KEYUP:
            if (e.key.repeat == 0)
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        xDir += 1.0;
                    break;
                    case SDLK_RIGHT:
                        xDir -= 1.0;
                    break;
                    default:
                        break;
                }
        default:
            break;
    }
}

void PlayerController::Update(const std::vector<BoxCollider2D*> &boxColliders, const double deltaTime) const {
    player->x += xDir * speed * deltaTime;
    if (boxCollider) {
        if (boxCollider->CheckCollision(boxColliders)) {
            player->x -= xDir * speed * deltaTime;
        }
    }
}

void PlayerController::Update(const std::vector<BoundaryCollider2D*> &boundaryColliders, const double deltaTime) const {
    player->x += xDir * speed * deltaTime;
    if (boxCollider) {
        if (boxCollider->CheckCollision(boundaryColliders) && !rigidBody->isGrounded) {
            player->x -= xDir * speed * deltaTime;
        }
    }
}
