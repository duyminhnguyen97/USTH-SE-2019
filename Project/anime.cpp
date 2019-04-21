#include "anime.h"
#include "graphics.h"

Anime::Anime() {

}

Anime::Anime(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float desX, float desY, float delay) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, desX, desY),
	frameIndex(0),
	timeElasped(0),
	delay(delay),
	currAnimation("")
{

}

void Anime::addAnimation(int frames, int sourceX, int sourceY, std::string name, int width, int height) {
	std::vector<SDL_Rect> animationRect;
	for (int i = 0; i < frames; i++) {
		SDL_Rect framesRect = { sourceX + i * width, sourceY, width, height };
		animationRect.push_back(framesRect);
	}
	this->animationSheets.insert(std::pair <std::string, std::vector<SDL_Rect>> (name, animationRect));
}

void Anime::playAnimation(std::string animation) {
	if (this->currAnimation != animation) {
		this->currAnimation = animation;
		this->frameIndex = 0;
	}
}

void Anime::update(float elaspedTime) {
	this->timeElasped += elaspedTime;
	if (this->timeElasped > this->delay) {
		this->timeElasped -= this->delay;
		if (this->frameIndex < this->animationSheets[this->currAnimation].size() - 1) {
			this->frameIndex++;
		}
		else {
			this->frameIndex = 0;
		}
	}
}

void Anime::draw(Graphics &graphics, float desX, float desY) {
	SDL_Rect desRect = { desX , desY , this->sourceRect.w, this->sourceRect.h };

	SDL_Rect sourceRect = this->animationSheets[this->currAnimation][this->frameIndex];
	graphics.renderCopyer(this->spriteTexture, &sourceRect, &desRect);
}

#pragma once
