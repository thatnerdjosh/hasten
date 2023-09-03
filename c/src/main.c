#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

#include "renderwindow.h"

const int gScreenWidth = 640;
const int gScreenHeight = 480;

int main(int argc, char *args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize. SDL_Error: %s\n",
                SDL_GetError());
        return 1;
    }

    if (!IMG_Init(IMG_INIT_PNG)) {
        fprintf(stderr, "IMG_init has failed. Error: %s\n", SDL_GetError());
        return 1;
    }

    RenderWindow window;
    int status = RenderWindow_ctor(&window, "GAME v1.0", 1280, 720);
    if (status != 0) {
        return status;
    }

    SDL_Texture *grass =
        RenderWindow_LoadTexture(&window, "../res/gfx/grass.png");

    Entity grassEntity;
    Entity_ctor(&grassEntity, 0, 600, grass);

    RenderWindow_Clear(&window);
    RenderWindow_Draw(&window, &grassEntity);
    RenderWindow_Display(&window);

    // Hack to get window to stay up
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;
        }
    }

    RenderWindow_dtor(&window);
    SDL_Quit();

    return 0;
}
