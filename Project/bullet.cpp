#include "bullet.h"
#include "player.h"
#include "graphics.h"

namespace bulletSpeed {
	const float bulletVel = 0.4f;
}

Bullet::Bullet() {

}

Bullet::Bullet(Graphics &graphics, const std::string filePath, int sourceX, int sourceY, int width, int height, float delay):
	dx(0),
	dy(0),
	timeElasped(0),
	delay(delay),
	isAlive(false)
{
	this->sourceRect = { sourceX,sourceY,width,height };
	this->bulletTex = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.createSurface(filePath));
	if (this->bulletTex == NULL) {
		printf("AAA");
	}
}

void Bullet::draw(Graphics &graphics) {
	if (isAlive) {
		SDL_Rect desRect = { this->x , this->y , this->sourceRect.w, this->sourceRect.h };
		graphics.renderCopyer(this->bulletTex, &sourceRect, &desRect);
	}
}

void Bullet::update(float elaspedTime) {
	if (isAlive) {
		this->x += dx * elaspedTime;
		this->y += dy * elaspedTime;
		this->timeElasped += elaspedTime;
		if (this->timeElasped > this->delay) {
			this->timeElasped -= this->delay;
		}
	}
}

void Bullet::shootBullet(Player &player) {
	this->x = player.getPlayerX();
	this->y = player.getPlayerY();
	switch (player.getDirection()) {
	case Left:
		this->dx = -bulletSpeed::bulletVel;
		this->dy = 0;
		isAlive = true;
		break;
	case Right:
		this->dx = +bulletSpeed::bulletVel;
		this->dy = 0;
		isAlive = true;
		break;
	case Up:
		this->dy = -bulletSpeed::bulletVel;
		this->dx = 0;
		isAlive = true;
		break;
	case Down:
		this->dy = +bulletSpeed::bulletVel;
		this->dx = 0;
		isAlive = true;
		break;
	default:
		break;
	}
}

bool Bullet::checkCollision1() {
	if (this->y < 0) {
		return true;
	}
	if (this->y + 16 > global::screenHeight) {
		return true;
	}
	if (this->x < 0) {
		return true;
	}
	if (this->x + 16 > global::screenWidth) {
		return true;
	}
	return false;
}

float Bullet::getBulletX() {
	return this->x;
}

float Bullet::getBulletY() {
	return this->y;
}