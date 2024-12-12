//
// Created by đỗ quyên on 12/12/24.
//

#include "BoxCollider2D.h"

#include "GameObject.h"


void BoxCollider2D::Update(const std::vector<BoxCollider2D*> &colliders, double deltaTime) {
    boxCollider->x = entity->x;
    boxCollider->y = entity->y;
    for (BoxCollider2D* collider : colliders) {
        if (collider != this) {
            if (boxCollider->x < collider->boxCollider->x + collider->boxCollider->w &&
                boxCollider->x + boxCollider->w > collider->boxCollider->x &&
                boxCollider->y < collider->boxCollider->y + collider->boxCollider->h &&
                boxCollider->y + boxCollider->h > collider->boxCollider->y) {

            }
        }
    }
}
