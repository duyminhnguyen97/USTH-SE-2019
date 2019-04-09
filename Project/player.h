#ifndef PLAYER_H
#define PLAYER_H

#include "animation.h"
#include <string>

class Graphics;

class Player : public Animation {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	void moveLeft();
	void moveRight();
	void stopMoving();
	void moveUp();
	void moveDown();

	virtual void animationDone(std::string currAnimation);
	virtual void setUpAnimation();
private:
	float dx, dy;	
	direction facing;
};

#endif