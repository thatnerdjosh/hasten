#include "renderwindow.h"

int RenderWindow_ctor(RenderWindow *self, char *title, int w, int h) {
    self->_window =
        SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (self->_window == NULL) {
        fprintf(stderr, "Window could not be created! SDL Error: %s\n",
                SDL_GetError());
        return -1;
    }

    self->_renderer =
        SDL_CreateRenderer(self->_window, -1, SDL_RENDERER_ACCELERATED);
    // TODO: Move to DEBUG
    fprintf(stderr, "constructed RenderWindow\n");
    return 0;
}

void RenderWindow_dtor(RenderWindow *self) {
    SDL_DestroyWindow(self->_window);
    // TODO: Move to DEBUG
    fprintf(stderr, "destructed RenderWindow\n");
}

SDL_Texture *RenderWindow_LoadTexture(RenderWindow *self,
                                      const char *file_path) {
    SDL_Texture *texture = IMG_LoadTexture(self->_renderer, file_path);
    if (texture == NULL)
        fprintf(stderr, "Failed to load texture. SDL Error: %s\n",
                SDL_GetError());

    return texture;
}

void RenderWindow_Clear(RenderWindow *self) {
    SDL_RenderClear(self->_renderer);
}

void RenderWindow_Draw(RenderWindow *self, Entity *entity) {
    SDL_Rect currentFrame = Entity_GetCurrentFrame(entity);
    SDL_Rect src;
    src.x = currentFrame.x;
    src.y = currentFrame.y;
    src.h = currentFrame.h;
    src.w = currentFrame.w;

    SDL_Rect dst;
    dst.x = Entity_GetX(entity);
    dst.y = Entity_GetY(entity);
    dst.h = currentFrame.h * 4;
    dst.w = currentFrame.w * 4;

    SDL_RenderCopy(self->_renderer, Entity_GetTexture(entity), &src, &dst);
}

void RenderWindow_Display(RenderWindow *self) {
    SDL_RenderPresent(self->_renderer);
}
