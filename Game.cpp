#include <SDL.h>
#include <iostream>
//#include <SDL_image.h>

#include <algorithm>
#include "Game.h"	
#include "graphics.h"
#include "Input.h"

// holds main game loop information



namespace {
	const int FPS = 100;
	const int MAX_FRAME_TIME = 5*1000;//5* 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	//IMG_Init(IMG_INIT_PNG);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;
	this->_player = Player(graphics, 100, 100);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true) {
		input.beginNewFrame();
		if (SDL_PollEvent(&event)) {
   			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		else if (input.wasKeyHeld(SDL_SCANCODE_LEFT) == true) {
			this->_player.moveLeft();
		}
		else if (input.wasKeyHeld(SDL_SCANCODE_RIGHT) == true) {
			this->_player.moveRight();
		}
		else if (input.wasKeyHeld(SDL_SCANCODE_UP) == true) {
			this->_player.moveUp();
		}
		else if (input.wasKeyHeld(SDL_SCANCODE_DOWN) == true) {
			this->_player.moveDown();
		}

		if (!input.wasKeyHeld(SDL_SCANCODE_LEFT) && !input.wasKeyHeld(SDL_SCANCODE_RIGHT)&&!input.wasKeyHeld(SDL_SCANCODE_UP) && !input.wasKeyHeld(SDL_SCANCODE_DOWN)) {
			this->_player.stopMoving();
		}
		
		SDL_Delay(1);
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game:: draw(Graphics& graphics) {
	graphics.clear();

	this->_player.draw(graphics);

	graphics.flip();
}

void Game:: update(float elapsedTime) {
	this->_player.update(elapsedTime);
}