//
// Created by đỗ quyên on 12/12/24.
//

#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H
#include <SDL_events.h>
#include "GameObject.h"


struct GameObject;

class PlayerController {
public:
    PlayerController(GameObject* entity, const double speed) : xDir(0){
        player = entity;
        this->speed = speed;
    }
    void HandleEvents(const SDL_Event &e);
    void Update(double deltaTime) const;
private:
    GameObject* player;
    double speed;
    double xDir;
};



#endif //PLAYERCONTROLLER_H
