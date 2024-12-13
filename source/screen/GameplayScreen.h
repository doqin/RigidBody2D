//
// Created by đỗ quyên on 12/12/24.
//

#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include <vector>
#include "component/GameScreen.h"

class GameStage;
class GameEngine;

class GameplayScreen final : public GameScreen {
public:
    GameEngine* game;
    SDL_Rect viewPort;
    const float FPS = 120.0f;
    const float frameDelay = 1000.0f / FPS;

    explicit GameplayScreen(GameEngine* game) {
        this->game = game;
    }

    void Init() override;
    void Cleanup() override;

    void Pause() override;
    void Resume() override;

    void HandleEvents() override;
    void Update() override;
    void Draw() override;

    void ChangeStage(GameStage *stage) override;
private:
    ~GameplayScreen() override = default;
    std::vector<GameStage*> stages;
};



#endif //GAMEPLAYSCREEN_H
