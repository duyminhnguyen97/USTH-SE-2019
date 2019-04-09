#include "level.h"
#include "graphics.h"

#include <SDL.h>

Level::Level() {

}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
	mapName(mapName),
	spawnPoint(spawnPoint),
	size(Vector2(0, 0))
{
	this->loadMap(mapName, graphics);
}

Level::~Level() {

}

void Level::loadMap(std::string mapName, Graphics &graphics) {
	this->backgroundTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage("Debug/images/BG.png"));
	this->size = Vector2(450, 320);
}

void Level::update(int elaspedTime) {

}

void Level::draw(Graphics &graphics) {
	SDL_Rect sourceRect = {0,0,64,64};
	SDL_Rect destRect;
	destRect.w = 64 * global::spriteScale;
	destRect.h = 64 * global::spriteScale;
	for (int x = 0; x < this->size.x / 64; x++) {
		for (int y = 0; y < this->size.y / 64; y++) {
			destRect.x = x * 64 * global::spriteScale;
			destRect.y = y * 64 * global::spriteScale;
			graphics.blitSurface(this->backgroundTexture, &sourceRect, &destRect);
		}
	}
}