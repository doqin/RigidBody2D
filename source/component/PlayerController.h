//
// Created by đỗ quyên on 12/12/24.
//

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include <SDL_events.h>
#include "GameObject.h"
#include "RigidBody2D.h"


struct GameObject;

class PlayerController {
public:
    PlayerController(GameObject* entity, RigidBody2D* rigidBody = nullptr, const double speed = 0) : xDir(0){
        player = entity;
        this->speed = speed;
        if (rigidBody) {
            this->rigidBody = rigidBody;
        }
    }
    void HandleEvents(const SDL_Event &e);
    void HandleEvents(const SDL_Event &e, RigidBody2D* rigidBody);
    void Update(double deltaTime) const;

    RigidBody2D* rigidBody;
private:
    GameObject* player;
    double speed;
    double xDir;
};



#endif //PLAYERCONTROLLER_H
