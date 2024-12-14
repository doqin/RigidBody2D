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
    SDL_Rect* boxCollider;
    BoxCollider2D(GameObject* entity, int x, int y, float w, float h) {
        this->entity = entity;
        boxCollider = new SDL_Rect(x - w/2.0, y - w/2.0, w, h);
    }
    BoxCollider2D(GameObject* entity, SDL_Rect* boxCollider) {
        this->entity = entity;
        this->boxCollider = boxCollider;
    }
    ~BoxCollider2D() = default;

    void Update();
    bool CheckCollision(const std::vector<BoxCollider2D *> &colliders) const;

    bool CheckCollision(const std::vector<BoundaryCollider2D *> &boundaryColliders) const;

private:
    GameObject* entity;
};



#endif //BOXCOLLIDER2D_H
