//
// Created by đỗ quyên on 12/12/24.
//

#include "BoxCollider2D.h"

#include "BoundaryCollider2D.h"
#include "GameObject.h"


void BoxCollider2D::Update() {
    boxCollider->x = entity->x - boxCollider->w / 2;
    boxCollider->y = entity->y - boxCollider->h / 2;
}

bool BoxCollider2D::CheckCollision(const std::vector<BoxCollider2D*> &colliders) const {
    bool isCollided = false;
    for (const BoxCollider2D* collider : colliders) {
        if (collider != this) {
            /*
            if (boxCollider->x < collider->boxCollider->x + collider->boxCollider->w &&
                boxCollider->x + boxCollider->w > collider->boxCollider->x &&
                boxCollider->y < collider->boxCollider->y + collider->boxCollider->h &&
                boxCollider->y + boxCollider->h > collider->boxCollider->y) {
                isCollided = true;
            }
            */
            isCollided = SDL_HasIntersection(boxCollider, collider->boxCollider);
            if (isCollided) {
                return isCollided;
            }
        }
    }
    return isCollided;
}

bool BoxCollider2D::CheckCollision(const std::vector<BoundaryCollider2D*> &boundaryColliders) const {
    for (BoundaryCollider2D* collider : boundaryColliders) {
        int y = collider->point.y + collider->vector.y * (boxCollider->x - collider->point.x) / collider->vector.x;
        if (y < boxCollider->y + boxCollider->h) {
            return true;
        }
    }
    return false;
}
