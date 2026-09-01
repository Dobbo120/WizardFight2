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
	//These are introduced but I have not implemented them.  They were originally for implementing movement, but may not be stored in the Wizard Class in the future

	sprite.setScale(Vector2f({ scale,scale }));
	sprite.setPosition({ (winX / 2) - (sprite.getLocalBounds().size.x * scale / 2), (winY / 2) - (sprite.getLocalBounds().size.y * scale / 2) });
	//This sets the Wizard in the center of the screen
}

Sprite Wizard::getSprite() {
	
	return sprite;
}

