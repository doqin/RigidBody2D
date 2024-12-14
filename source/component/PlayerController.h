//
// Created by đỗ quyên on 12/12/24.
//

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include <SDL_events.h>

#include "BoundaryCollider2D.h"
#include "GameObject.h"
#include "RigidBody2D.h"


struct GameObject;

class PlayerController {
public:
    explicit PlayerController(GameObject* entity, RigidBody2D* rigidBody = nullptr, BoxCollider2D* boxCollider = nullptr, const float speed = 0, const int jumpForce = -10) : xDir(0){
        player = entity;
        this->speed = speed;
        if (rigidBody) {
            this->rigidBody = rigidBody;
        }
        if (boxCollider) {
            this->boxCollider = boxCollider;
        }
        if (jumpForce != 0) {
            this->jumpForce = jumpForce;
        }
    }
    void HandleEvents(const SDL_Event &e);
    void HandleEvents(const SDL_Event &e, RigidBody2D* rigidBody);
    void Update(const std::vector<BoxCollider2D *> &boxColliders, float deltaTime) const;

    void Update(const std::vector<BoundaryCollider2D *> &boundaryColliders, float deltaTime) const;

    RigidBody2D* rigidBody;
private:
    GameObject* player;
    BoxCollider2D *boxCollider;
    float speed;
    float xDir;
    float jumpForce;
};



#endif //PLAYERCONTROLLER_H
