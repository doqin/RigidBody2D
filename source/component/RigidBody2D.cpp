//
// Created by đỗ quyên on 12/12/24.
//

#include "RigidBody2D.h"

void RigidBody2D::Update(double deltaTime) {
    if (!isGrounded) {
        entity->y += velocity * deltaTime + 0.5 * acceleration * deltaTime * deltaTime;
        velocity += acceleration * deltaTime;
        if (velocity >= 0) {
            isGrounded = true;
        }
    }
}

