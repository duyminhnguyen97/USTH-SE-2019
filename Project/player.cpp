#include "player.h"
#include "graphics.h"
#include "enemy.h"
#include "bullet.h"

namespace playerConstant {
	const float walkSpeed = 0.2f;
}

Player::Player() {

}

Player::Player(Graphics &graphics, float x, float y) : //x-y is spawn point on the map
	Anime(graphics, "Debug/images/Char1.png", 0, 0, 25, 38, x, y, 150),
	dx(0),
	dy(0),
	isInvincible(true),
	maxHealth(10000),
	currHealth(10000)
{
	this->setUpAnimation();
}

void Player::setUpAnimation() {
	this->addAnimation(4, 0, 0, "RunDown", 25, 38);
	this->addAnimation(1, 0, 0, "IdleDown", 25, 38);
	this->addAnimation(4, 0, 38, "RunUp", 25, 38);
	this->addAnimation(1, 0, 38, "IdleUp", 25, 38);
	this->addAnimation(4, 0, 76, "RunLeft", 25, 38);
	this->addAnimation(1, 0, 76, "IdleLeft", 25, 38);
	this->addAnimation(4, 0, 114, "RunRight", 25, 38);
	this->addAnimation(1, 0, 114, "IdleRight", 25, 38);
}

void Player::moveUp() {
	this->dy = -playerConstant::walkSpeed;
	this->playAnimation("RunUp");
	this->facing = Up;
}

void Player::moveDown() {
	this->dy = +playerConstant::walkSpeed;
	this->playAnimation("RunDown");
	this->facing = Down;
}

void Player::moveLeft() {
	this->dx = -playerConstant::walkSpeed;
	this->playAnimation("RunLeft");
	this->facing = Left;
}

void Player::moveRight() {
	this->dx = +playerConstant::walkSpeed;
	this->playAnimation("RunRight");
	this->facing = Right;
}

void Player::stopMovingX() {
	this->dx = 0.0f;
}

void Player::stopMovingY() {
	this->dy = 0.0f;
}

void Player::checkCollision() {
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

void Player::handleCollision() {
	this->currHealth -= 1;
	if (this->currHealth < 0) {
		this->endGame = true;
	}
}

void Player::update(float elaspedTime) {
	this->x += this->dx*elaspedTime;
	this->y += this->dy*elaspedTime;
	Anime::update(elaspedTime);
}

void Player::draw(Graphics &graphics) {
	Anime::draw(graphics, this->x, this->y);

}

float Player::getPlayerX() {
	return this->x;
}

float Player::getPlayerY() {
	return this->y;
}

direction Player::getDirection() {
	return this->facing;
}

int Player::getCurHealth() {
	return this->currHealth;
}

int Player::getMaxHealth() {
	return this->maxHealth;
}

bool Player::endGames(){
	return this->endGame;
}