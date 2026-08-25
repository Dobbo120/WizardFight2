#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Wizard {
private:

	const std::filesystem::path wizardPath = "graphics/Wizard.png";
	Texture texture;
	Sprite sprite;

	float playerX;
	float playerY;

public:
	Wizard(float scale);

	Sprite getSprite();



};