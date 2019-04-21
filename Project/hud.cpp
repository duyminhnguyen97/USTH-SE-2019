#include "hud.h"
#include "graphics.h"
#include "player.h"


Hud::Hud() {

}

Hud::Hud(Graphics &graphics){
	this->healthBarSprite = Sprite(graphics, "Debug/images/TextBox.png", 0, 40, 64, 8, 35, 70);
	this->currHealthBar = Sprite(graphics, "Debug/images/TextBox.png", 0, 25, 39, 5, 83, 72);
}

void Hud::update(Player &player) {
	this->player = player;

	float num = (float)this->player.getCurHealth() / this->player.getMaxHealth();
	this->currHealthBar.setSourceWidth(std::floor(num * 39));
}

void Hud::draw(Graphics &graphics) {
	this->healthBarSprite.draw(graphics, this->healthBarSprite.getX(), this->healthBarSprite.getY());
	this->currHealthBar.draw(graphics, this->currHealthBar.getX(), this->currHealthBar.getY());
}
