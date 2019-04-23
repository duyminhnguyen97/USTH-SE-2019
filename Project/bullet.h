#ifndef BULLET_H
#define BULLET_H

#include "player.h"

class Graphics;

class Bullet {
public:
	Bullet();
	Bullet(Graphics &graphics, const std::string filePath, int sourceX, int sourceY, int width, int height);
	void draw(Graphics &graphics);
	void update(float elaspedTime);
	void shootBullet(Player &player);
	float getBulletX();
	float getBulletY();
protected:
	SDL_Rect sourceRect;
	SDL_Texture *bulletTex;

	float x, y;
	bool isAlive;
private:
	float dx, dy;
};


#endif // !BULLET_H
