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

	float gameX;
	float gameY;
	
public:

	BackgroundManager();

	void generate(int screenWidth, int screenHeight, float scale, std::wstring textureFile);

	Sprite getTile(int tileNum);

	int getLength();

	Vector2f getPos();

	Vector2f move(float xDir, float yDir, Time elTime);
};