//
// Created by đỗ quyên on 12/12/24.
//

#ifndef BOXCOLLIDER2D_H
#define BOXCOLLIDER2D_H
#include <SDL_rect.h>
#include <vector>

#include "BoundaryCollider2D.h"


struct GameObject;

class BoxCollider2D {
public:
    GameObject* entity;
    SDL_Rect* boxCollider;
    BoxCollider2D(GameObject* entity, const int x, const int y, const int w, const int h) {
        this->entity = entity;
        boxCollider = new SDL_Rect(x - w/2, y - w/2, w, h);
    }
    BoxCollider2D(GameObject* entity, SDL_Rect* boxCollider) {
        this->entity = entity;
        this->boxCollider = boxCollider;
    }
    ~BoxCollider2D() = default;

    void Update() const;
    bool CheckCollision(const BoxCollider2D* collider) const;
    bool CheckCollision(const BoundaryCollider2D* boundaryCollider) const;
};



#endif //BOXCOLLIDER2D_H
