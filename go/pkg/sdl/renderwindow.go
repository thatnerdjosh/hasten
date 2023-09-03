package sdl

import (
	"github.com/veandco/go-sdl2/img"
	"github.com/veandco/go-sdl2/sdl"
)

type RenderWindow struct {
	window   *sdl.Window
	renderer *sdl.Renderer
}

func CreateRenderWindow(title string, w int32, h int32) (r RenderWindow, err error) {
	r.window, err = sdl.CreateWindow(title, sdl.WINDOWPOS_UNDEFINED, sdl.WINDOWPOS_UNDEFINED, w, h, sdl.WINDOW_SHOWN)
	if err != nil {
		return r, err
	}

	r.renderer, err = sdl.CreateRenderer(r.window, -1, sdl.RENDERER_ACCELERATED)

	return r, err
}

func (r *RenderWindow) Draw(e *Entity) error {
	src := e.GetCurrentFrame()

	dst := sdl.Rect{}
	// TODO: Check if there is a way to represent the location as float.
	dst.X = int32(e.GetX())
	dst.Y = int32(e.GetY())
	// TODO: Support w/h of other sizes
	dst.W = src.W * 4
	dst.H = src.H * 4

	return r.renderer.Copy(e.GetTexture(), &src, &dst)
}

func (r *RenderWindow) Display() {
	r.renderer.Present()
}

func (r *RenderWindow) LoadTexture(filePath string) (*sdl.Texture, error) {
	return img.LoadTexture(r.renderer, filePath)
}

func (r RenderWindow) Cleanup() (err error) {
	err = r.window.Destroy()
	if err != nil {
		return err
	}

	return r.renderer.Destroy()
}
