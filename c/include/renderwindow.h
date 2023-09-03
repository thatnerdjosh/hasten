#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "entity.h"

typedef struct {
    // public:
    // private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
} RenderWindow;

int RenderWindow_ctor(RenderWindow *self, char *title, int w, int h);
void RenderWindow_dtor(RenderWindow *self);

SDL_Texture *RenderWindow_LoadTexture(RenderWindow *self,
                                      const char *file_path);
void RenderWindow_Clear(RenderWindow *self);
void RenderWindow_Draw(RenderWindow *self, Entity *entity);
void RenderWindow_Display(RenderWindow *self);
