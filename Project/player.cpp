#include "player.h"
#include "graphics.h"

namespace playerConstant {
	const float walkSpeed = 0.2f;

}

Player::Player() {

}

Player::Player(Graphics &graphics, float x, float y) :
	Animation(graphics, "Debug/images/Char1.png", 0, 0, 25, 38, x, y, 150)
{
	graphics.loadImage("Debug/images/Char1.png");
	this->setUpAnimation();
}

void Player::setUpAnimation() {
	this->addAnimation(4, 0, 0, "RunDown", 25, 38, Vector2(0, 0));
	this->addAnimation(1, 0, 0, "IdleDown", 25, 38, Vector2(0, 0));
	this->addAnimation(4, 0, 38, "RunUp", 25, 38, Vector2(0, 0));
	this->addAnimation(1, 0, 38, "IdleUp", 25, 38, Vector2(0, 0));
	this->addAnimation(4, 0, 76, "RunLeft", 25, 38, Vector2(0, 0));
	this->addAnimation(1, 0, 76, "IdleLeft", 25, 38, Vector2(0, 0));
	this->addAnimation(4, 0, 114, "RunRight", 25, 38, Vector2(0, 0));
	this->addAnimation(1, 0, 114, "IdleRight", 25, 38, Vector2(0, 0));
}

void Player::animationDone(std::string currAnimation) {

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

void Player::stopMoving() {
	this->dx = 0.0f;
	this->dy = 0.0f;

	this->playAnimation(this->facing == Right ? "IdleRight" : "IdleLeft");

	if (facing == Down) {
		this->playAnimation("IdleDown");
	}
	if (facing == Up) {
		this->playAnimation("IdleUp");
	}
}

void Player::update(float elaspedTime) {
	this->x += this->dx*elaspedTime;
	this->y += this->dy*elaspedTime;
	Animation::update(elaspedTime);
}

void Player::draw(Graphics &graphics) {
	Animation::draw(graphics, this->x, this->y);

}