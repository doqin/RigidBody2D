//
// Created by đỗ quyên on 13/12/24.
//

#ifndef POINT2D_H
#define POINT2D_H
struct Point2D {
    double x, y;
    Point2D() {
        x = 0;
        y = 0;
    }
    Point2D(const double x, const double y) {
        this->x = x;
        this->y = y;
    }
};

#endif //POINT2D_H
