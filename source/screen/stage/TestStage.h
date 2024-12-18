//
// Created by đỗ quyên on 12/12/24.
//

#ifndef TESTSTAGE_H
#define TESTSTAGE_H

#include <vector>

#include "component/CircleCollider2D.h"
#include "component/DeltaTime.h"
#include "component/GameStage.h"
#include "component/RigidBody2D.h"
#include "component/ScreenRepresentation.h"
#include "screen/GameplayScreen.h"

class BoundaryCollider2D;
class BoxCollider2D;
class PlayerController;
struct GameObject;

class TestStage final : public GameStage {
public:
    GameplayScreen* gameScreen;
    SDL_Event e;
    Uint64 NOW = SDL_GetTicks();
    Uint64 LAST = 0;
    float deltaTime = 0;

    explicit TestStage(GameplayScreen* gameScreen);

    void Init() override;

    void Cleanup() override;

    void Pause() override;

    void Resume() override;

    void HandleEvents() override;

    void FixedUpdate() override;

    void Update() override;

    void Draw() override;
private:
    // Components' list
    std::vector<GameObject*> gameObjects;
    std::vector<ScreenRepresentation*> sprites;
    std::vector<PlayerController*> controllers;
    std::vector<RigidBody2D*> rigidBodies;
    std::vector<BoxCollider2D*> colliders;
    std::vector<BoundaryCollider2D*> boundaries;
    std::vector<CircleCollider2D*> circles;

    // Stage size
    int stageWidth;
    int stageHeight;
};



#endif //TESTSTAGE_H
