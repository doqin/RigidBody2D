//
// Created by đỗ quyên on 13/12/24.
//

#ifndef BOUNDARYCOLLIDER2D_H
#define BOUNDARYCOLLIDER2D_H
#include <SDL_render.h>
#include <vector>

#include "Point2D.h"
#include "Vector2D.h"

struct GameObject;
class BoxCollider2D;

class BoundaryCollider2D {
public:
    BoundaryCollider2D(int x, int y, const Vector2D normal) {
        this->normal = normal;
        this->point.x = x;
        this->point.y = y;
        this->vector.x = normal.y;
        this->vector.y = -normal.x;
    }
    ~BoundaryCollider2D();
    void DrawCollider(SDL_Renderer* gRenderer, int x1, int x2) const;
    Vector2D normal;
    Vector2D vector;
    Point2D point;
};



#endif //BOUNDARYCOLLIDER2D_H
