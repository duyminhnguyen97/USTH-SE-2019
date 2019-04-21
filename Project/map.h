#pragma once
#ifndef MAP_H
#define MAP_H

#include "global.h"
#include <SDL.h>
#include <string>

class Graphics;

class Map {
public:
	Map();
	Map(Graphics &graphics, const std::string filePath);

	void update(float elaspedTime);
	void draw(Graphics &graphics);
protected:
	SDL_Rect sourceRect;
	SDL_Texture *mapTex;
private:

};


#endif