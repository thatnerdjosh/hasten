#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

const int gScreenWidth  = 640;
const int gScreenHeight = 480;

int main() {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	// TODO: Abstract and allow toggle between OpenGL/SDL native.
	window = SDL_CreateWindow(
		"SDL", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		gScreenWidth, gScreenHeight,
		SDL_WINDOW_SHOWN
	);

	if(window == NULL) {
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	screenSurface = SDL_GetWindowSurface( window );
	SDL_FillRect(
		screenSurface, NULL,
		SDL_MapRGB(
			screenSurface->format, 
			0xFF, 0xFF, 0xFF
		)
	);
	SDL_UpdateWindowSurface( window );

	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
