//
// Created by đỗ quyên on 12/12/24.
//

#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H
#include "GameObject.h"

class RigidBody2D {
public:
    explicit RigidBody2D(GameObject* entity) {
        this->entity = entity;
        isGrounded = false;
        gravity = 9.8;
        mass = 1;
        velocity = 0;
        acceleration = mass * gravity;
    }
    void Update(double deltaTime);
private:
    GameObject* entity;
    bool isGrounded;
    double gravity;
    double mass;
    double velocity;
    double acceleration;
};



#endif //RIGIDBODY2D_H
