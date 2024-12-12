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

    virtual void Init(const char *title, int width, int height, bool fullscreen);

    virtual void Cleanup();

    virtual void ChangeScreen(GameScreen *state);

    virtual void PushScreen(GameScreen *state);

    virtual void PopScreen();

    virtual void HandleEvents();

    virtual void Update();

    virtual void Draw();

    virtual bool Running() const { return mRunning; }
    virtual void Quit() { mRunning = false; }

protected:
    // The stack of states
    std::vector<GameScreen*> screens;

    bool mFullscreen;
    bool mRunning;
};



#endif //GAMEENGINE_H
