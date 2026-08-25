#include "Wizard.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Wizard::Wizard(float winX, float winY, float scale) :
	texture("graphics/Wizard.png"),
	sprite(texture)
	
{

	playerX = 0;
	playerY = 0;

	sprite.setScale(Vector2f({ scale,scale }));
	sprite.setPosition({ (winX / 2) - (sprite.getLocalBounds().size.x * scale / 2), (winY / 2) - (sprite.getLocalBounds().size.y * scale / 2) });
}

Sprite Wizard::getSprite() {
	
	return sprite;
}

