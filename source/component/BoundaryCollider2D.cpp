//
// Created by đỗ quyên on 13/12/24.
//
#include "BoundaryCollider2D.h"
#include "Vector2D.h"
#include "Point2D.h"
#include <SDL_render.h>

BoundaryCollider2D::~BoundaryCollider2D() {
    delete &normal;
    delete &vector;
    delete &point;
}

void BoundaryCollider2D::DrawCollider(SDL_Renderer* gRenderer, int x1, int x2) {
    for (int i = x1; i <= x2; i++) {
        SDL_RenderDrawPoint(gRenderer, i, point.y + vector.y * (i - point.x) / vector.x);
    }
}
