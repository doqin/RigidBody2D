
#include <iostream>

#include "component/GameEngine.h"
#include "screen/GameplayScreen.h"

int main() {
    GameEngine game;
    game.Init("RigidBody2D", 1280, 480, false);
    game.ChangeScreen(new GameplayScreen(&game));

    // Timer
    float timer = 0;

    // Delta time
    Uint32 NOW = SDL_GetTicks();
    Uint32 LAST = 0;

    // Game loop
    while (game.Running()) {
        constexpr float fixedStep = 0.02f;
        game.HandleEvents();
        while (timer > fixedStep) {
            game.FixedUpdate();
            timer -= fixedStep;
        }
        game.Update();
        game.Draw();
        LAST = NOW;
        NOW = SDL_GetTicks();
        const float deltaTime = static_cast<float>(NOW - LAST) / 1000.f;
        timer += deltaTime;
    }
    game.Cleanup();
    return 0;
}
