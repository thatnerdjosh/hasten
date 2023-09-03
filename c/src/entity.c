#include "entity.h"

void Entity_ctor(Entity *self, float x, float y, SDL_Texture *texture) {
    self->_x = x;
    self->_y = y;
    self->_texture = texture;

    self->_currentFrame.x = 0;
    self->_currentFrame.y = 0;
    self->_currentFrame.w = 64;
    self->_currentFrame.h = 64;
}

float Entity_GetX(Entity *self) { return self->_x; }
float Entity_GetY(Entity *self) { return self->_y; }

SDL_Texture *Entity_GetTexture(Entity *self) { return self->_texture; }
SDL_Rect Entity_GetCurrentFrame(Entity *self) { return self->_currentFrame; }
