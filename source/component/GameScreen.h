//
// Created by đỗ quyên on 12/12/24.
//

#ifndef GAMESCREEN_H
#define GAMESCREEN_H
#include "GameEngine.h"
#include "GameStage.h"
#include <vector>

class GameScreen {
public:
    virtual ~GameScreen() = default;

    virtual void Init() = 0;
    virtual void Cleanup() {
        // Cleanup the all stages
        while ( !stages.empty() ) {
            stages.back()->Cleanup();
            stages.pop_back();
        }
    }

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    virtual void ChangeStage(GameStage* stage) = 0;
private:
    std::vector<GameStage*> stages;
};



#endif //GAMESCREEN_H
