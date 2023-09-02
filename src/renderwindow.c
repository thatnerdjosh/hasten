#include "renderwindow.h"

int RenderWindow_ctor(RenderWindow *self, char *title, int w, int h) {
    self->_window =
        SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (self->_window == NULL) {
        fprintf(stderr, "Window could not be created! SDL Error: %s\n",
                SDL_GetError());
        return 1;
    }

    // self->_renderer =
    //     SDL_CreateRenderer(self->_window, -1, SDL_RENDERER_ACCELERATED);
    // TODO: Move to DEBUG
    fprintf(stderr, "constructed RenderWindow\n");
    return 0;
}

void RenderWindow_dtor(RenderWindow *self) {
    SDL_DestroyWindow(self->_window);
    // TODO: Move to DEBUG
    fprintf(stderr, "destructed RenderWindow\n");
}