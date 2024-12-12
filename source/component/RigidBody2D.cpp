//
// Created by đỗ quyên on 12/12/24.
//

#include "RigidBody2D.h"

#include <iostream>

#include "BoxCollider2D.h"

void RigidBody2D::Update(double deltaTime) {
    entity->y += velocity * deltaTime - 0.5 * acceleration * deltaTime * deltaTime;
    velocity -= acceleration * deltaTime;
}

void RigidBody2D::Update(const std::vector<BoxCollider2D*> &boxColliders, const double deltaTime) {
    velocity += acceleration * deltaTime;
    entity->y += velocity * deltaTime;
    if (boxCollider)
        if (boxCollider->CheckCollision(boxColliders)) {
            entity->y -= velocity * deltaTime;
            velocity = 0;
            if (jumpForce != 0) {
                velocity = jumpForce;
                entity->y += velocity * deltaTime;
                jumpForce = 0;
            }
        }
}

