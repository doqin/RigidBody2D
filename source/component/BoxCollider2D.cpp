//
// Created by đỗ quyên on 12/12/24.
//

#include "BoxCollider2D.h"

#include "GameObject.h"


void BoxCollider2D::Update() {
    boxCollider->x = entity->x - boxCollider->w / 2;
    boxCollider->y = entity->y - boxCollider->h / 2;
}

bool BoxCollider2D::CheckCollision(const std::vector<BoxCollider2D*> &colliders) const {
    bool isCollided = false;
    for (BoxCollider2D* collider : colliders) {
        if (collider != this) {
            if (boxCollider->x < collider->boxCollider->x + collider->boxCollider->w &&
                boxCollider->x + boxCollider->w > collider->boxCollider->x &&
                boxCollider->y < collider->boxCollider->y + collider->boxCollider->h &&
                boxCollider->y + boxCollider->h > collider->boxCollider->y) {
                isCollided = true;
            }
        }
    }
    return isCollided;
}
