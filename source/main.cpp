
#include "component/GameEngine.h"
#include "screen/GameplayScreen.h"

int main() {
    GameEngine game;
    game.Init("RigidBody2D", 1280, 480, false);
    game.ChangeScreen(new GameplayScreen(&game));
    while (game.Running()) {
        game.HandleEvents();
        game.Update();
        game.Draw();
    }
    game.Cleanup();
    return 0;
}
