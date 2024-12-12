//
// Created by đỗ quyên on 12/12/24.
//

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
struct GameObject {
    double x, y;
    GameObject() {
        x = 0;
        y = 0;
    }
    GameObject(const int x, const int y) {
        this->x = x;
        this->y = y;
    }
};
#endif //GAMEOBJECT_H
