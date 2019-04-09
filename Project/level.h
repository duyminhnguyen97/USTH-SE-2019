#ifndef LEVEL_H
#define LEVEL_H

#include "global.h"
class Graphics;
struct SDL_Texture;
#include <string>

class Level {
public:
	Level();
	Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics);
	~Level();

	void update(int elaspedTime);
	void draw(Graphics &graphics);
private:
	std::string mapName;
	Vector2 spawnPoint;
	Vector2 size;
	SDL_Texture* backgroundTexture;

	void loadMap(std::string mapName, Graphics &graphics);
};


#endif


#pragma once
