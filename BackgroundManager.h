#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class BackgroundManager {
private:

	Texture backgroundTexture;

	std::vector<Sprite> backgroundSprite;
	//Dynamic so that I could add sprites with a for loop

	int seed;
	//I wanted to have a reusable seed, I think I will 

	int tileHeight;
	int tileWidth;
	//Allows for tiles that are not square

	float gameX;
	float gameY;
	//Also implemented a game position in the Background Manager
	
public:

	BackgroundManager();

	void generate(int screenWidth, int screenHeight, float scale, std::wstring textureFile);
	//generates at the beginning of the game

	Sprite getTile(int tileNum);

	int getLength();
	//Returns how many sprites are in the vector

	Vector2f getPos();
	//returns the x,y coords of the game

	Vector2f move(float xDir, float yDir, Time elTime);
	//move was never properly implemented, I took a look at how tilemaps were handled in my book at this point
};