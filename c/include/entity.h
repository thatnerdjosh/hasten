#pragma once
#include <SDL2/SDL.h>

typedef struct {
    // public:
    // private:
    float _x, _y;
    SDL_Rect _currentFrame;
    SDL_Texture *_texture;
} Entity;

void Entity_ctor(Entity *self, float x, float y, SDL_Texture *texture);
float Entity_GetX(Entity *self);
float Entity_GetY(Entity *self);
SDL_Texture *Entity_GetTexture(Entity *self);
SDL_Rect Entity_GetCurrentFrame(Entity *self);
