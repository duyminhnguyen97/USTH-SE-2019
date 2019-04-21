#include "map.h"
#include "graphics.h"



Map::Map() {

}

Map::Map(Graphics &graphics, std::string filePath) {
	this->sourceRect = { 0,0,64,64 };
	this->mapTex = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.createSurface(filePath));
	if (this->mapTex == NULL) {
		printf("\nNo such files exist\n");
	}
}

void Map::update(float elaspedTime){
	
}

void Map::draw(Graphics &graphics) {
	SDL_Rect desRect;
	desRect.w = 128;
	desRect.h = 128;
	for (int x = 0; x < global::screenWidth / 64; x++) {
		for (int y = 0; y < global::screenHeight / 64; y++) {
			desRect.x = x * 64 * global::spriteScale;
			desRect.y = y * 64 * global::spriteScale;
			graphics.renderCopyer(mapTex, &sourceRect, &desRect);
		}
	}
}
