#include "BackgroundManager.h"
#include <iostream>

BackgroundManager::BackgroundManager() {
	//I don't know if this works the way I want I want it to, but ostensibly it'll mean that I if I regenerate with the same background texture, it'll generate it the same
	seed = time(0);

	//The width and the height of the tiles in the texture in pixels
	tileWidth = 32;

	tileHeight = 32;

	gameX = 0;
	gameY = 0;

}

void BackgroundManager::generate(int screenWidth, int screenHeight, float scale, std::wstring textureFile) {

	//Seeding the random number generator with the seed from initializing the BackgroundManager
	srand(seed);

	//Debug likes it if I catch the return
	if (backgroundTexture.loadFromFile(std::filesystem::path(textureFile)) == false) {
		std::cout << "You done fucked up, that's an invalid path for the texture";
	}

	//Full width and height of the texture in pixels
	int textureWidth = backgroundTexture.getSize().x;
	int textureHeight = backgroundTexture.getSize().y;

	//This little codeblock here sets up the background sprites by randomly grabbing subsections of the texture, the nested for loops place the tiles on the screen by determining how many tiles it takes to
	//fill the screen, in the future I would like to add a buffer of tiles on all edges of the screen
	for (int i = 0; i < (screenWidth / (tileWidth * scale)); i++) {
		for (int j = 0; j < (screenHeight / (tileHeight * scale)); j++) {

			//Here's that fancy little code that grabs subsections from the background texture
			Sprite tile(backgroundTexture, IntRect({ (rand() % (textureWidth/tileWidth)) * tileWidth, (rand() % (textureHeight/tileHeight)) * tileHeight }, {tileWidth, tileHeight}));
			tile.setScale({scale,scale});
			tile.setPosition(Vector2f({ i * tileWidth * scale,j * tileHeight * scale }));

			backgroundSprite.push_back(tile);

		}
	}

}

Sprite BackgroundManager::getTile(int tileNum) {
	
	return(backgroundSprite.at(tileNum));

}

int BackgroundManager::getLength() {

	return(backgroundSprite.size());

}

Vector2f BackgroundManager::getPos() {
	return Vector2f({ gameX,gameY });
}

Vector2f BackgroundManager::move(float xDir, float yDir, Time eltime) {
	if (xDir * yDir > 0) {
		//Greater than zero is for ostensibly including gamepad support down the line, but at the moment, I'm only implementing 45 degree angles
		//Also, instead of operating with a normal mathematical means of limiting, I am purposefully going to make diagonal movement marginally faster;
		xDir *= 0.71f;
		yDir *= 0.71f;
	}
	gameX = gameX + xDir;
	gameY = gameY + yDir;

	return(Vector2f({ gameX,gameY }));
}