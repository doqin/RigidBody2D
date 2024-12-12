//
// Created by đỗ quyên on 12/12/24.
//

#ifndef BOXCOLLIDER2D_H
#define BOXCOLLIDER2D_H
#include <SDL_rect.h>
#include <vector>


struct GameObject;

class BoxCollider2D {
public:
    BoxCollider2D(GameObject* entity, SDL_Rect* boxCollider) {
        this->entity = entity;
        this->boxCollider = boxCollider;
    }
    ~BoxCollider2D() = default;
    void Update(const std::vector<BoxCollider2D*> &colliders, double deltaTime);
private:
    GameObject* entity;
    SDL_Rect* boxCollider;
};



#endif //BOXCOLLIDER2D_H
