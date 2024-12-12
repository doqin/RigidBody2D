//
// Created by đỗ quyên on 12/12/24.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Sprite {
public:
    // Initializes variables
    Sprite();
    // Deallocates memory
    ~Sprite();

    // Loads image at specified path
    bool loadFromFile(SDL_Renderer* mRenderer, const std::string& path);

    // Deallocates texture
    void free();

    // Set color modulation
    void setColor(Uint8 red, Uint8 green, Uint8 blue) const;

    // Set blending
    void setBlendMode(SDL_BlendMode blending) const;

    // Set alpha modulation
    void setAlpha(Uint8 alpha);

    // Renders texture at given point
    void render(SDL_Renderer *mRenderer, int x, int y, const SDL_Rect *dstrect = nullptr, const SDL_Rect *clip = nullptr,
                double angle = 0.0, const SDL_Point *center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    void render(SDL_Renderer *mRenderer, int x, int y, int w, int h, const SDL_Rect *clip = nullptr, double angle = 0.0,
                const SDL_Point *center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    void render(SDL_Renderer *mRenderer, Uint8 alpha, int x, int y, const SDL_Rect *clip = nullptr, double angle = 0.0,
                const SDL_Point *center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;

    //Gets image dimensions
    int getWidth() const;
    int getHeight() const;

private:
    // The actual hardware texture
    SDL_Texture* mTexture;

    // Image dimensions
    int mWidth;
    int mHeight;
    Uint8 mAlpha;
};

#endif //SPRITE_H
