#include "graphics.h"
#include <SDL_image.h>
#include <iostream>
#include "global.h"


Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(global::screenWidth, global::screenHeight, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "YEETS");

}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}

void Graphics::renderCopyer(SDL_Texture *tex, SDL_Rect *sourceRect, SDL_Rect *desRect) {
	SDL_RenderCopy(this->renderer, tex, sourceRect, desRect);	
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->renderer;
}

SDL_Surface* Graphics::createSurface(const std::string filePath) {
	SDL_Surface* tempSurf = IMG_Load(filePath.c_str());
	return tempSurf;
}

void Graphics::clear() {
	SDL_RenderClear(this->renderer);
}

void Graphics::show() {
	SDL_RenderPresent(this->renderer);
}