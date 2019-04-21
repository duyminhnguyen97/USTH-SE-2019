#include "enemy.h"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace monsterConstant {
	const float monsterMs = 0.2f;
	int monsterDmg = 1;
}

Enemy::Enemy(){

}

Enemy::Enemy(Graphics &graphics, float x, float y) :
	Anime(graphics, "Debug/images/Enemies.png", 0, 0, 24, 24, x, y, 150),
	dx(0),
	dy(0),
	score(0),
	isAlive(true)
{
	this->setUpAnimation();
}

void Enemy::setUpAnimation() {
	this->addAnimation(3, 0, 0, "MonsterLeft", 24, 24);
	this->addAnimation(3, 0, 24, "MonsterRight", 24, 24);
	this->addAnimation(1, 120, 0, "MonsterHitLeft", 24, 24);
	this->addAnimation(1, 120, 24, "MonsterHitRight", 24, 24);
}

void Enemy::monsterMove(Player &player) {
	if (isAlive) {
		if (this->x < player.getPlayerX()) {
			this->dx = +monsterConstant::monsterMs;
			this->playAnimation("MonsterRight");
			this->face = Right;
		}
		if (this->x > player.getPlayerX()) {
			this->dx = -monsterConstant::monsterMs;
			this->playAnimation("MonsterLeft");
			this->face = Left;
		}
		if (this->y < player.getPlayerY()) {
			this->dy = +monsterConstant::monsterMs;
		}
		if (this->y > player.getPlayerY()) {
			this->dy = -monsterConstant::monsterMs;
		}
	}
}

void Enemy::checkCollision() {
	if (this->y < 0) {
		this->y = 0;
	}
	if (this->y + 38 > global::screenHeight) {
		this->y = global::screenHeight - 38;
	}
	if (this->x < 0) {
		this->x = 0;
	}
	if (this->x + 25 > global::screenWidth) {
		this->x = global::screenWidth - 25;
	}
}

void Enemy::draw(Graphics &graphics) {
	if (isAlive) {
		Anime::draw(graphics, this->x, this->y);
	}
}

void Enemy::update(float elaspedTime) {
	if (isAlive) {
		this->x += dx * elaspedTime;
		this->y += dy * elaspedTime;
		Anime::update(elaspedTime);
	}
}

float Enemy::getEnemyX() {
	return this->x;
}

float Enemy::getEnemyY() {
	return this->y;
}

void Enemy::handleCollision() {
	this->dx = 0;
	this->dy = 0;
	if (face == Right) {
		this->playAnimation("MonsterHitRight");
	}
	if (face == Left) {
		this->playAnimation("MonsterHitLeft");
	}
}

void Enemy::isHit() {
	srand(time(NULL));
	int a = rand() % 1280 + 1;
	int b = rand() % 960 + 1;
	this->score++;
	std::cout << "Your score is: " << this->score << "\n";
	isAlive = false;
	this->x = a;
	this->y = b;
	isAlive = true;
}
