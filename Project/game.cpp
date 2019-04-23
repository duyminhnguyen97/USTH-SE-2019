#include "game.h"
#include <iostream>
#include <SDL_image.h>
#include <Windows.h>
#include <time.h>
#include <SDL.h>
#include "hud.h"



namespace {			//this is the frame limits setup
	const float FPS = 60;
	const float MAX_FRAME_TIME = 1000 / FPS;
	const unsigned int BULLET_INTERVAL = 1500;
	unsigned int LAST_BULLET_TIME = 0;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

void Game::gameLoop() {		//this is the function to loop the game.
	Graphics graphics;
	SDL_Event e;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	this->sprite = Player(graphics, 450, 350);
	this->sprite.playAnimation("IdleDown");
	this->enemy = Enemy(graphics, 800, 800);
	this->enemy.playAnimation("MonsterLeft");
	this->map = Map(graphics, "Debug/images/BG.png");
	this->bullet = Bullet(graphics, "Debug/images/bullet.png", 0, 0, 16, 16);
	this->hud = Hud(graphics);

	while (true) {
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					return;
				case SDLK_a:
					sprite.moveLeft();
					break;
				case SDLK_d:
					sprite.moveRight();
					break;
				case SDLK_s:
					sprite.moveDown();
					break;
				case SDLK_w:
					sprite.moveUp();
					break;
				case SDLK_SPACE:
					if (LAST_BULLET_TIME + BULLET_INTERVAL <= SDL_GetTicks()) {
						LAST_BULLET_TIME = SDL_GetTicks();
						bullet.shootBullet(sprite);
					}
				default:
					break;
				}
			}
			else if (e.type == SDL_KEYUP && e.key.repeat == 0) {
				switch (e.key.keysym.sym) {
				case SDLK_a:
					sprite.stopMovingX();
					break;
				case SDLK_w:
					sprite.stopMovingY();
					break;
				case SDLK_d:
					sprite.stopMovingX();
					break;
				case SDLK_s:
					sprite.stopMovingY();
					break;
				default:
					break;
				}
			}
			if (e.type == SDL_QUIT) {
				return;
			}
		}
		sprite.checkCollision();
		enemy.monsterMove(sprite);

		if (enemyCollision()) { // bullet vs monster
			enemy.isHit();
			}

		if (isCollision()) { // monster vs player
			sprite.handleCollision();
			enemy.handleCollision();
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		float ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
		this->draw(graphics);
		if (sprite.endGames()) {
			std::cout << "You're Dead.";
			SDL_Delay(2500);
			return;
		}
	}
}

void Game::update(float elaspedTime) {		//this function updates the game every frame.
	this->sprite.update(elaspedTime);
	this->enemy.update(elaspedTime);
	this->bullet.update(elaspedTime);
	this->hud.update(sprite);
}

void Game::draw(Graphics &graphics) {		//this function draws everything on the screen.
	graphics.clear();
	this->map.draw(graphics);
	this->sprite.draw(graphics);
	this->enemy.draw(graphics);
	this->bullet.draw(graphics);
	this->hud.draw(graphics);
	graphics.show();
}

bool Game::isCollision() {					//this function handles monster vs player collision
	float leftA, topA, rightA, botA;
	float leftB, topB, rightB, botB;

	leftA = sprite.getPlayerX();
	rightA = sprite.getPlayerX() + 25;
	topA = sprite.getPlayerY();
	botA = sprite.getPlayerY() + 38;

	leftB = enemy.getEnemyX();
	rightB = enemy.getEnemyX() + 24;
	topB = enemy.getEnemyY();
	botB = enemy.getEnemyY() + 24;
	
	if (botA <= topB) {
		return false;
	}
	if (topA >= botB) {
		return false;
	}
	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	}
	return true;
}

bool Game::enemyCollision() {				//this function handles bullet vs monster collisions.
	float leftA, topA, rightA, botA;
	float leftB, topB, rightB, botB;

	leftA = bullet.getBulletX();
	rightA = bullet.getBulletX() + 16;
	topA = bullet.getBulletY();
	botA = bullet.getBulletY() + 16;

	leftB = enemy.getEnemyX();
	rightB = enemy.getEnemyX() + 24;
	topB = enemy.getEnemyY();
	botB = enemy.getEnemyY() + 24;

	if (botA <= topB) {
		return false;
	}
	if (topA >= botB) {
		return false;
	}
	if (rightA <= leftB) {
		return false;
	}
	if (leftA >= rightB) {
		return false;
	}
	return true;
}
