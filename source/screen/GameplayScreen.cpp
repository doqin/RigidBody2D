//
// Created by đỗ quyên on 12/12/24.
//

#include "GameplayScreen.h"

#include "component/GameEngine.h"
#include "stage/TestStage.h"

void GameplayScreen::Init() {
    viewPort = {0, 0, game->mWidth, game->mHeight};
    ChangeStage(new TestStage(this));
}

void GameplayScreen::Cleanup() {
    // Cleanup the all stages
    while ( !stages.empty() ) {
        stages.back()->Cleanup();
        stages.pop_back();
    }
    game = nullptr;
    delete this;
}

void GameplayScreen::Pause() {
}

void GameplayScreen::Resume() {
}

void GameplayScreen::HandleEvents() {
    stages.back()->HandleEvents();
}

void GameplayScreen::Update() {
    stages.back()->Update();
}

void GameplayScreen::Draw() {
    stages.back()->Draw();
}

void GameplayScreen::ChangeStage(GameStage* stage) {
    stages.push_back(stage);
    stages.back()->Init();
}