//
// Created by đỗ quyên on 12/12/24.
//

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL.h>
#include <vector>

class GameScreen;

class GameEngine final {
public:
    int mHeight;
    int mWidth;
    SDL_Window *screen;
    SDL_Renderer *renderer;

    ~GameEngine() = default;

    GameEngine() = default;

    void Init(const char *title, int width, int height, bool fullscreen);

    void Cleanup();

    void ChangeScreen(GameScreen *state);

    void PushScreen(GameScreen *state);

    void PopScreen();

    void HandleEvents();

    void FixedUpdate();

    void Update();

    void Draw();

    bool Running() const { return mRunning; }
    void Quit() { mRunning = false; }

protected:
    // The stack of states
    std::vector<GameScreen*> screens;

    bool mFullscreen;
    bool mRunning;
};



#endif //GAMEENGINE_H
