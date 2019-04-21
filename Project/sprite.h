#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Graphics;

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string filePath, int sourceX, int sourceY, int width, int height, float desX, float desY);
	void draw(Graphics &graphics, float x, float y);
	void setSourceRectX(int value);
	void setSourceRectY(int value);
	void setSourceWidth(int value);
	void setSourceHeight(int value);

	const inline float getX() const {
		return this->x;
	}

	const inline float getY() const {
		return this->y;
	}
protected:
	SDL_Rect sourceRect;
	SDL_Texture *spriteTexture;
	float x, y;
private:

};

// Loads up the texture of the Sprite.

#endif // !SPRITE_H



#pragma once
