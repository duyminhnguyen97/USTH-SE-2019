#include "animation.h"
#include "graphics.h"

Animation::Animation() {

}

Animation::Animation(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate) :
	Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
	frameIndex(0),
	timeElasped(0),
	timeToUpdate(timeToUpdate),
	visible(true),
	currAnimationOnce(false),
	currAnimation("")
{
}

void Animation::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset) {
	std::vector<SDL_Rect> rectangles;
	for (int i = 0; i < frames; i++) {
		SDL_Rect newRect = { x + i * width, y, width, height };
		rectangles.push_back(newRect);
	}
	this->animation.insert(std::pair <std::string, std::vector<SDL_Rect>> (name, rectangles));
	this->offSets.insert(std::pair <std::string, Vector2> (name, offset));

}

void Animation::resetAnimation() {
	this->animation.clear();
	this->offSets.clear();

}

void Animation::playAnimation(std::string animation, bool once) {
	this->currAnimationOnce = once;
	if (this->currAnimation != animation) {
		this->currAnimation = animation;
		this->frameIndex = 0;
	}
}

void Animation::setVisible(bool visible) {
	this->visible = visible;
	this->animationDone(this->currAnimation);
}

void Animation::update(float elaspedTime) {
	Sprite::update();
	
	this->timeElasped += elaspedTime;
	if (this->timeElasped > this->timeToUpdate) {
		this->timeElasped -= this->timeToUpdate;
		if (this->frameIndex < this->animation[this->currAnimation].size() - 1) {
			this->frameIndex++;
		}
		else {
			if (this->currAnimationOnce == true) {
				this->setVisible(false);
			}
			this->frameIndex = 0;
			this->animationDone(this->currAnimation);	
		}
	}
}

void Animation::draw(Graphics &graphics,int x,int y) {
	if (this->visible) {
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + this->offSets[this->currAnimation].x;
		destinationRectangle.y = y + this->offSets[this->currAnimation].y;
		destinationRectangle.w = this->sourceRect.w;
		destinationRectangle.h = this->sourceRect.h;

		SDL_Rect sourceRect = this->animation[this->currAnimation][this->frameIndex];
		graphics.blitSurface(this->spriteSheet,&sourceRect,&destinationRectangle);
	}
}

void Animation::stopAnimation() {

}
