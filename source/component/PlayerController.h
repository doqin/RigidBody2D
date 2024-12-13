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
    explicit PlayerController(GameObject* entity, RigidBody2D* rigidBody = nullptr, BoxCollider2D* boxCollider = nullptr, const double speed = 0) : xDir(0){
        player = entity;
        this->speed = speed;
        if (rigidBody) {
            this->rigidBody = rigidBody;
        }
        if (boxCollider) {
            this->boxCollider = boxCollider;
        }
    }
    void HandleEvents(const SDL_Event &e);
    void HandleEvents(const SDL_Event &e, RigidBody2D* rigidBody);
    void Update(const std::vector<BoxCollider2D *> &boxColliders, double deltaTime) const;

    void Update(const std::vector<BoundaryCollider2D *> &boundaryColliders, double deltaTime) const;

    RigidBody2D* rigidBody;
private:
    GameObject* player;
    const BoxCollider2D *boxCollider;
    double speed;
    double xDir;
};



#endif //PLAYERCONTROLLER_H
