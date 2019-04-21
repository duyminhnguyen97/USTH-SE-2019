#ifndef HUD_H
#define HUD_H

#include "sprite.h"
#include "player.h"

class Graphics;

class Hud {
public:
	Hud();
	Hud(Graphics &graphics);
	void update(Player &player);
	void draw(Graphics &graphics);
protected:

private:
	Player player;
	
	Sprite healthBarSprite;
	Sprite healthNumber1;
	Sprite currHealthBar;
};


#endif // !HUD_H
