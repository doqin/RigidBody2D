//
// Created by đỗ quyên on 12/12/24.
//

#include "RigidBody2D.h"

#include <iostream>

#include "BoundaryCollider2D.h"
#include "BoxCollider2D.h"

void RigidBody2D::Update(const std::vector<BoundaryCollider2D*> &boundaryColliders, const std::vector<BoxCollider2D*> &boxColliders) {
    isGrounded = false;
    velocity += acceleration;
    entity->y += velocity;
    if (boxCollider) {
        boxCollider->Update();
        for (const BoundaryCollider2D* collider : boundaryColliders) {
            if (const float y = static_cast<float>(collider->point.y) + collider->vector.y
                * (boxCollider->boxCollider->x - collider->point.x) / static_cast<float>(collider->vector.x);
                y < boxCollider->boxCollider->y + boxCollider->boxCollider->h) {
                this->RollBack(velocity);
            }
        }
        for (const BoxCollider2D* collider : boxColliders) {
            if (boxCollider->CheckCollision(collider)) {
                this->RollBack(velocity);
            }
        }
    }
    else if (circleCollider) {
        circleCollider->Update();
        for (const BoundaryCollider2D* collider : boundaryColliders) {
            if (const float y = (collider->point.y) + collider->vector.y
                * (circleCollider->x - collider->point.x) / static_cast<float>(collider->vector.x);
                y < circleCollider->y + circleCollider->radius) {
                entity->y = y - circleCollider->radius;
                circleCollider->Update();
                velocity = 0;
                isGrounded = true;
            }
        }
        for (const BoxCollider2D* collider : boxColliders) {
            if (circleCollider->CheckCollision(collider)) {
                this->RollBack(velocity);
            }
        }
    }
    if (jumpForce != 0 && isGrounded) {
        velocity = jumpForce;
        entity->y += velocity;
        jumpForce = 0;
        isGrounded = false;
    }
}

void RigidBody2D::RollBack(const float distance) {
    entity->y -= distance;
    circleCollider->Update();
    velocity = 0;
    isGrounded = true;
}

