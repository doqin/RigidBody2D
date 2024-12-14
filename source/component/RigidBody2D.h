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
    explicit RigidBody2D(GameObject* entity, BoxCollider2D* boxCollider = nullptr, const int mass = 1) {
        this->entity = entity;
        if (boxCollider != nullptr) {
            this->boxCollider = boxCollider;
        }
        isGrounded = false;
        this->mass = mass;
        velocity = 0;
        acceleration = mass;
    }
    void Update();
    void Update(const std::vector<BoxCollider2D *> &boxColliders);
    void Update(const std::vector<BoundaryCollider2D *> &boundaryColliders);

    float jumpForce;
    bool isGrounded;
private:
    GameObject* entity;
    float velocity;
    float mass;
    float acceleration;
};



#endif //RIGIDBODY2D_H
