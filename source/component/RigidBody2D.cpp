//
// Created by đỗ quyên on 12/12/24.
//

#include "RigidBody2D.h"

#include <iostream>

#include "BoundaryCollider2D.h"
#include "BoxCollider2D.h"

void RigidBody2D::Update(double deltaTime) {
    entity->y += velocity * deltaTime - 0.5 * acceleration * deltaTime * deltaTime;
    velocity -= acceleration * deltaTime;
}

void RigidBody2D::Update(const std::vector<BoxCollider2D*> &boxColliders, const double deltaTime) {
    isGrounded = false;
    velocity += acceleration * deltaTime;
    entity->y += velocity * deltaTime;
    if (boxCollider) {
        if (boxCollider->CheckCollision(boxColliders)) {
            entity->y -= velocity * deltaTime;
            velocity = 0;
            isGrounded = true;
            if (jumpForce != 0) {
                velocity = jumpForce;
                entity->y += velocity * deltaTime;
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

void RigidBody2D::Update(const std::vector<BoundaryCollider2D*> &boundaryColliders, const double deltaTime) {
    isGrounded = false;
    velocity += acceleration * deltaTime;
    entity->y += velocity * deltaTime;
    if (boxCollider) {
        for (BoundaryCollider2D* collider : boundaryColliders) {
            int y = collider->point.y + collider->vector.y * (boxCollider->boxCollider->x - collider->point.x) / collider->vector.x;
            if (y < boxCollider->boxCollider->y + boxCollider->boxCollider->h) {
                entity->y -= velocity * deltaTime;
                velocity = 0;
                isGrounded = true;
                if (jumpForce != 0) {
                    velocity = jumpForce;
                    entity->y += velocity * deltaTime;
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
}

