//
// Created by đỗ quyên on 13/12/24.
//

#ifndef POINT2D_H
#define POINT2D_H
struct Point2D {
    float x, y;
    Point2D() {
        x = 0;
        y = 0;
    }
    Point2D(const float x, const float y) {
        this->x = x;
        this->y = y;
    }
};

#endif //POINT2D_H
