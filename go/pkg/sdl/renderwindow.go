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

func (r *RenderWindow) Draw(texture *sdl.Texture) error {
	src := sdl.Rect{}
	src.X = 0
	src.Y = 0
	src.W = 32
	src.H = 32

	dst := sdl.Rect{}
	dst.X = 0
	dst.Y = 0
	dst.W = 32
	dst.H = 32

	return r.renderer.Copy(texture, &src, &dst)
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
