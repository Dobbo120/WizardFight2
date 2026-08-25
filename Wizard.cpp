#include "Wizard.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Wizard::Wizard(float scale)
	: texture(),
	sprite(texture)
{

	texture.loadFromFile("graphics/Wizard.png");
	sprite.setTexture(texture);

	playerX = 0;
	playerY = 0;

	sprite.setPosition({ playerX,playerY });
}

Sprite Wizard::getSprite() {
	return sprite;
}

