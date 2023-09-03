package sdl

import (
	"github.com/veandco/go-sdl2/sdl"
)

type Entity struct {
	x            float32
	y            float32
	texture      *sdl.Texture
	currentFrame sdl.Rect
}

func CreateEntity(x float32, y float32, texture *sdl.Texture) *Entity {
	return &Entity{
		x:       x,
		y:       y,
		texture: texture,
		currentFrame: sdl.Rect{
			X: 0,
			Y: 0,
			W: 64,
			H: 64,
		},
	}
}

func (e *Entity) GetCurrentFrame() sdl.Rect {
	return e.currentFrame
}

func (e *Entity) GetX() float32 {
	return e.x
}

func (e *Entity) GetY() float32 {
	return e.y
}

func (e *Entity) GetTexture() *sdl.Texture {
	return e.texture
}
