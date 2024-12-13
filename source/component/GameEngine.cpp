//
// Created by đỗ quyên on 12/12/24.
//

#include <SDL.h>
#include "GameEngine.h"
#include "GameScreen.h"

void GameEngine::Init(const char* title, int width, int height, bool fullscreen) {
    int flags = 0;

    // Save the screen dimensions
    mWidth = width;
    mHeight = height;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    //  Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }

    // Get flags
    if ( fullscreen ) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    // Create the screen window
    screen = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);
    if (screen == nullptr) {
        printf ("SDL_CreateWindow Error: %s\n", SDL_GetError());
    }

    // Create the renderer
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    }

    mFullscreen = fullscreen;
    mRunning = true;

}

void GameEngine::Cleanup()
{
    // Cleanup the all screens
    while ( !screens.empty() ) {
        screens.back()->Cleanup();
        screens.pop_back();
    }

    // Switch back to windowed mode so other
    // Programs won't get accidentally resized
    if ( mFullscreen ) {
        SDL_SetWindowFullscreen(screen, 0);
        SDL_SetWindowSize(screen, mWidth, mHeight);
    }

    // shutdown SDL
    SDL_Quit();
}

void GameEngine::ChangeScreen(GameScreen* state)
{
    // cleanup the current state
    if ( !screens.empty() ) {
        screens.back()->Cleanup();
        screens.pop_back();
    }

    // store and init the new state
    screens.push_back(state);
    screens.back()->Init();
}

void GameEngine::PushScreen(GameScreen* state)
{
    // Pause current state
    if ( !screens.empty() ) {
        screens.back()->Pause();
    }

    // Store and init the new state
    screens.push_back(state);
    screens.back()->Init();
}

void GameEngine::PopScreen()
{
    // Cleanup the current state
    if ( !screens.empty() ) {
        screens.back()->Cleanup();
        screens.pop_back();
    }

    // Resume previous state
    if ( !screens.empty() ) {
        screens.back()->Resume();
    }
}


void GameEngine::HandleEvents()
{
    // Let the state handle events
    screens.back()->HandleEvents();
}

void GameEngine::Update()
{
    // Let the state update the game
    screens.back()->Update();
}

void GameEngine::Draw()
{
    // Let the state draw the screen
    screens.back()->Draw();
}