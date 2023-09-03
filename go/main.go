package main

import (
	"fmt"
	"github.com/veandco/go-sdl2/img"
	"github.com/veandco/go-sdl2/sdl"
	"os"

	hastensdl "github.com/thatnerdjosh/hasten/go/pkg/sdl"
)

func main() {
	if err := sdl.Init(sdl.INIT_VIDEO); err != nil {
		panic(err)
	}

	if err := img.Init(img.INIT_PNG); err != nil {
		panic(err)
	}

	defer sdl.Quit()

	window, err := hastensdl.CreateRenderWindow("Test Game", 1280, 720)
	if err != nil {
		// TODO: Handle errors better
		panic(err)
	}

	grass, err := window.LoadTexture("../res/gfx/grass.png")
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error creating texture: %s", err.Error())
	}

	grassEntity := hastensdl.CreateEntity(0, 600, grass)
	err = window.Draw(grassEntity)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error drawing texture: %s", err.Error())
	}

	window.Display()

	running := true
	for running {
		for event := sdl.PollEvent(); event != nil; event = sdl.PollEvent() {
			switch event.(type) {
			case *sdl.QuitEvent:
				println("Quit")
				running = false
				break
			}
		}
	}

	err = window.Cleanup()
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error cleaning up: %s", err.Error())
	}
}
