#include "sprite.h"
#include "graphics.h"
#include "global.h"

Sprite::Sprite() {

}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) : x(posX),y(posY) {
	this->sourceRect.x = sourceX;
	this->sourceRect.y = sourceY;																					//create sourceRectangular
	this->sourceRect.w = width;
	this->sourceRect.h = height;

	this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));			//create textures from surfaces created by graphics.cpp
	if (this->spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite() {

}

void Sprite::draw(Graphics &graphics, int x, int y) {
	SDL_Rect destinationRectangle = { x,y,this->sourceRect.w * global::spriteScale,this->sourceRect.h * global::spriteScale };							//create destinationRectangular
	graphics.blitSurface(this->spriteSheet, &this->sourceRect, &destinationRectangle);																	//blit in graphics.cpp
}

void Sprite::update() {

}