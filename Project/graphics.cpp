#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "global.h"
#undef main

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(global::screenWidth, global::screenHeight, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window,"YAAAAAAAAAAA");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->window);

}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	if (this->spriteSheets.count(filePath) == 0) {
		this->spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(this->renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	SDL_RenderPresent(this->renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->renderer;
}
