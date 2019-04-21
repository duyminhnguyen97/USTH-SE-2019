#pragma once
#include "sprite.h"
#include "graphics.h"
#include "global.h"


Sprite::Sprite() {

}

Sprite::Sprite(Graphics &graphics, const std::string filePath, int sourceX, int sourceY, int width, int height, float desX, float desY) :
	 x(desX),y(desY) 
{
	this->sourceRect.x = sourceX;
	this->sourceRect.y = sourceY;																					
	this->sourceRect.w = width;
	this->sourceRect.h = height;


	this->spriteTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.createSurface(filePath));
	if (this->spriteTexture == NULL) {
		printf("\nError: Unable to load image\n");
	}

}

void Sprite::draw(Graphics &graphics, float x, float y) {
	SDL_Rect destinationRectangle = { x, y, this->sourceRect.w * global::spriteScale,
			this->sourceRect.h * global::spriteScale };
	graphics.renderCopyer(this->spriteTexture, &this->sourceRect, &destinationRectangle);
}

void Sprite::setSourceRectX(int value) {
	this->sourceRect.x = value;
}

void Sprite::setSourceRectY(int value) {
	this->sourceRect.y = value;
}

void Sprite::setSourceWidth(int value) {
	this->sourceRect.w = value;
}

void Sprite::setSourceHeight(int value) {
	this->sourceRect.h = value;
}

	
