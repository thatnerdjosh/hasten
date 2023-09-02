#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    // public:
    // private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
} RenderWindow;

int RenderWindow_ctor(RenderWindow *self, char *title, int w, int h);
void RenderWindow_dtor(RenderWindow *self);
