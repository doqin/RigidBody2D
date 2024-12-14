//
// Created by đỗ quyên on 13/12/24.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H
struct Vector2D {
    float x, y;
    Vector2D() {
        x = 0;
        y = 0;
    }
    Vector2D(const float x, const float y) {
        this->x = x;
        this->y = y;
    }
};
#endif //VECTOR2D_H
