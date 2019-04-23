#ifndef  GAME_H
#define GAME_H

#include "graphics.h"
#include "player.h"
#include "map.h"
#include "enemy.h"
#include "bullet.h"
#include "hud.h"

class Graphics;

class Game {
public:
	Game();
	void gameLoop();
	void update(float elapsedTime);
	void draw(Graphics &graphics);
	bool isCollision();
	bool enemyCollision();
protected:
private:
	Player sprite;
	Map map;
	Enemy enemy;
	Bullet bullet;
	Hud hud;
};

#endif // ! GAME_H
