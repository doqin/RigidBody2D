//
// Created by đỗ quyên on 12/12/24.
//

#include "BoxCollider2D.h"

#include "BoundaryCollider2D.h"
#include "GameObject.h"


void BoxCollider2D::Update() const {
    boxCollider->x = entity->x - boxCollider->w / 2;
    boxCollider->y = entity->y - boxCollider->h / 2;
}

bool BoxCollider2D::CheckCollision(const BoxCollider2D* collider) const {
    bool isCollided = false;
    isCollided = SDL_HasIntersection(boxCollider, collider->boxCollider);
    if (isCollided) {
        return isCollided;
    }
    return isCollided;
}

bool BoxCollider2D::CheckCollision(const BoundaryCollider2D* boundaryCollider) const {
    int y = boundaryCollider->point.y + boundaryCollider->vector.y * (boxCollider->x - boundaryCollider->point.x) / boundaryCollider->vector.x;
    if (y < boxCollider->y + boxCollider->h) {
        return true;
    }
    return false;
}
