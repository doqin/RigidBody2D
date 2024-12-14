//
// Created by đỗ quyên on 12/12/24.
//

#include "RigidBody2D.h"

#include <iostream>

#include "BoundaryCollider2D.h"
#include "BoxCollider2D.h"

void RigidBody2D::Update() {
    velocity -= acceleration;
    entity->y += velocity;
}

void RigidBody2D::Update(const std::vector<BoxCollider2D*> &boxColliders) {
    isGrounded = false;
    velocity += acceleration;
    entity->y += velocity;
    if (boxCollider) {
        boxCollider->boxCollider;
        if (boxCollider->CheckCollision(boxColliders)) {
            entity->y -= velocity;
            velocity = 0;
            isGrounded = true;
            if (jumpForce != 0) {
                velocity = jumpForce;
                entity->y += velocity;
                jumpForce = 0;
                isGrounded = false;
            }
        }
        else {
            if (jumpForce != 0) {
                jumpForce = 0;
            }
        }
    }
}

void RigidBody2D::Update(const std::vector<BoundaryCollider2D*> &boundaryColliders) {
    isGrounded = false;
    velocity += acceleration;
    entity->y += velocity;
    if (boxCollider) {
        boxCollider->Update();
        for (const BoundaryCollider2D* collider : boundaryColliders) {
            if (const float y = static_cast<float>(collider->point.y) + collider->vector.y
                * (boxCollider->boxCollider->x - collider->point.x) / static_cast<float>(collider->vector.x);
                y < boxCollider->boxCollider->y + boxCollider->boxCollider->h) {
                entity->y -= velocity;
                boxCollider->Update();
                while (y < boxCollider->boxCollider->y + boxCollider->boxCollider->h) {
                    entity->y -= 1;
                    boxCollider->Update();
                }
                velocity = 0;
                isGrounded = true;
            }
        }
        if (jumpForce != 0) {
            velocity = jumpForce;
            entity->y += velocity;
            jumpForce = 0;
            isGrounded = false;
        }

    }
}

