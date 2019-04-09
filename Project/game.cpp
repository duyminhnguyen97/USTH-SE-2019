#include <SDL.h>
#include "game.h"
#include "graphics.h"
#include "input.h"
#include <Windows.h>

namespace {
	const int FPS = 50;
	const float maxFrameTime = 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {


}

void Game::gameLoop() {
	Graphics graphics;
	SDL_Event e;
	Input input;

	int lastUpdateTime = SDL_GetTicks();

	this->player = Player(graphics, 100, 100);
	this->level = Level("Map",Vector2(100,100),graphics);

	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				if (e.key.repeat == 0) {
					input.keyDownEvent(e);
				}
			}
			else if (e.type == SDL_KEYUP) {
				input.keyUpEvent(e);
			}
			if (e.type == SDL_QUIT) {
				return;
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}
		else if (input.isKeyHeld(SDL_SCANCODE_A) == true) {
			this->player.moveLeft();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_D) == true) {
			this->player.moveRight();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_W) == true) {
			this->player.moveUp();
		}
		else if (input.isKeyHeld(SDL_SCANCODE_S) == true) {
			this->player.moveDown();
		}
		if (!input.isKeyHeld(SDL_SCANCODE_A) && !input.isKeyHeld(SDL_SCANCODE_D) && !input.isKeyHeld(SDL_SCANCODE_W) && !input.isKeyHeld(SDL_SCANCODE_S)) {
			this->player.stopMoving();
		}

		const int currTimeMs = SDL_GetTicks();
		int elaspedTimeMs = currTimeMs - lastUpdateTime;
		this->update(min(elaspedTimeMs, maxFrameTime));
		lastUpdateTime = currTimeMs;

		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics) {
	graphics.clear();
	this->level.draw(graphics);
	this->player.draw(graphics);
	graphics.flip();
}

void Game::update(float elapsedTime) {
	this->player.update(elapsedTime);

}