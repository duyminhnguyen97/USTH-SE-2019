#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "anime.h"
#include "global.h"
#include "player.h"

class Graphics;

class Enemy : public Anime {
public:
	Enemy();
	Enemy(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elaspedTime);
	void monsterMove(Player &player);
	void checkCollision();
	void handleCollision();
	void isHit();

	float getEnemyX();
	float getEnemyY();
	virtual void setUpAnimation();
protected:
	bool isAlive;
private:
	int score;
	float dx, dy;
	direction face;
	Player player;
};


#endif