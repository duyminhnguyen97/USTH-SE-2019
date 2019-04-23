#ifndef PLAYER_H
#define PLAYER_H

#include "anime.h"
#include "global.h"

class Graphics;

class Player : public Anime {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);
	void moveLeft();
	void moveRight();
	void stopMovingX();
	void stopMovingY();
	void moveUp();
	void moveDown();
	void checkCollision();
	float getPlayerX();
	float getPlayerY();

	int getCurHealth();
	int getMaxHealth();
	bool endGames();
		

	direction getDirection();

	void handleCollision();
	bool endGame = false;
	virtual void setUpAnimation();
protected:
private:
	int maxHealth;
	int currHealth;
	float dx, dy;
	direction facing;
};

#endif