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
                        xDir -= 1;
                        break;
                    case SDLK_RIGHT:
                        xDir += 1;
                        break;
                    default:
                        break;
                }
            break;
        case SDL_KEYUP:
            if (e.key.repeat == 0)
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        xDir += 1;
                        break;
                    case SDLK_RIGHT:
                        xDir -= 1;
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
                        xDir -= 1 * speed;
                        break;
                    case SDLK_RIGHT:
                        xDir += 1 * speed;
                        break;
                    default:
                        break;
                }
            switch (e.key.keysym.sym) {
                case SDLK_UP:
                    if (rigidBody->isGrounded)
                        rigidBody->jumpForce = -jumpForce;
                    break;
                default:
                    break;
            }
        break;
        case SDL_KEYUP:
            if (e.key.repeat == 0)
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        xDir += 1 * speed;
                    break;
                    case SDLK_RIGHT:
                        xDir -= 1 * speed;
                    break;
                    default:
                        break;
                }
        default:
            break;
    }
}

void PlayerController::Update(const std::vector<BoxCollider2D*> &boxColliders) const {
    std::cout << xDir << std::endl;
    player->x += xDir;
    if (boxCollider) {
        boxCollider->Update();
        for (const BoxCollider2D* collider : boxColliders) {
            if (boxCollider->CheckCollision(collider)) {
                player->x -= xDir;
                boxCollider->Update();
            }
        }
    }
    else if (circleCollider) {
        circleCollider->Update();
        for (const BoxCollider2D* collider : boxColliders) {
            if (circleCollider->CheckCollision(collider)) {
                player->x -= xDir;
                circleCollider->Update();
            }
        }
    }
}

void PlayerController::Update(const std::vector<BoundaryCollider2D*> &boundaryColliders) const {
    player->x += xDir;
    if (boxCollider) {
        for (const BoundaryCollider2D* boundaryCollider : boundaryColliders) {
            if (boxCollider->CheckCollision(boundaryCollider)) {
                player->x -= xDir;
            }
        }
    }
    else if (circleCollider) {
        for (const BoundaryCollider2D* boundaryCollider : boundaryColliders) {
            if (circleCollider->CheckCollision(boundaryCollider)) {
                player->x -= xDir;
            }
        }
    }
}
