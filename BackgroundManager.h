#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class BackgroundManager {
private:

	Texture backgroundTexture;

	std::vector<Sprite> backgroundSprite;

	int seed;

	int tileHeight;

	int tileWidth;
	
public:

	BackgroundManager();

	void generate(int screenWidth, int screenHeight, float scale, std::wstring textureFile);

	Sprite getTile(int tileNum);

	int getLength();

};