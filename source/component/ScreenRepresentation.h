//
// Created by đỗ quyên on 12/12/24.
//

#ifndef SCREENREPRESENTATION_H
#define SCREENREPRESENTATION_H

#include <SDL_render.h>
#include "GameObject.h"
#include "Sprite.h"

struct ScreenRepresentation {
    Sprite* sprite;
    GameObject* gameObject;

    ScreenRepresentation(GameObject* entity, Sprite* texture) {
        gameObject = entity;
        sprite = texture;
    }
};

#endif //SCREENREPRESENTATION_H
