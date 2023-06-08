#pragma once
#include "settings.h"

class LivesIndicator {
public:
	LivesIndicator(sf::Vector2f pos);
	void update();
	void draw(sf::RenderWindow& window);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

LivesIndicator::LivesIndicator(sf::Vector2f pos) {
	texture.loadFromFile("images\\life_icon.png");
	sprite.setTexture(texture);
	sprite.setPosition(pos);
	sprite.setScale(0.18, 0.18);
}

void LivesIndicator::update() {}

void LivesIndicator::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}