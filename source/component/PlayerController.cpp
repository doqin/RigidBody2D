//
// Created by đỗ quyên on 12/12/24.
//

#include "PlayerController.h"
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

void PlayerController::Update(const double deltaTime) const {
    player->x += xDir * speed * deltaTime;
}
