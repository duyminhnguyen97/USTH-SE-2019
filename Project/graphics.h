#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <map>


class Graphics {
public:
	Graphics();
	~Graphics();
	
	void renderCopyer(SDL_Texture *tex, SDL_Rect *sourceRect, SDL_Rect *desRect);
	void clear();
	void show();

	SDL_Renderer* getRenderer() const;
	SDL_Surface* createSurface(const std::string filePath);
protected:
private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	std::map<std::string, SDL_Surface*> spriteSheets;
};

#endif