//
// Created by đỗ quyên on 12/12/24.
//

#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H
#include <vector>

#include "BoundaryCollider2D.h"
#include "GameObject.h"

class BoxCollider2D;

class RigidBody2D {
public:
    BoxCollider2D* boxCollider;
    explicit RigidBody2D(GameObject* entity, BoxCollider2D* boxCollider = nullptr) {
        this->entity = entity;
        if (boxCollider != nullptr) {
            this->boxCollider = boxCollider;
        }
        isGrounded = false;
        gravity = 9.8;
        mass = 0.00015;
        velocity = 0;
        acceleration = mass * gravity;
    }
    void Update(double deltaTime);
    void Update(const std::vector<BoxCollider2D*> &boxColliders, double deltaTime);
    void Update(const std::vector<BoundaryCollider2D*> &boundaryColliders, double deltaTime);

    double jumpForce;
    bool isGrounded;
private:
    GameObject* entity;
    double velocity;
    double gravity;
    double mass;
    double acceleration;
};



#endif //RIGIDBODY2D_H
