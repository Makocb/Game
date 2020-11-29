#include <SDL.h>

#include "graphics.h"

//all information dealing with graphics

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(800, 800, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Debree");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}