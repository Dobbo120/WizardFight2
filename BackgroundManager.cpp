#include "BackgroundManager.h"
#include <iostream>

BackgroundManager::BackgroundManager() {
	//I don't know if this works the way I want I want it to, but ostensibly it'll mean that I if I regenerate with the same background texture, it'll generate it the same
	seed = time(0);

	//The width and the height of the tiles in the texture in pixels
	tileWidth = 32;

	tileHeight = 32;

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

	//This little codeblock here sets up the background sprites by randomly grabbing subsections of the texture
	for (int i = 0; i < (screenWidth / (tileWidth * scale)); i++) {
		for (int j = 0; j < (screenHeight / (tileHeight * scale)); j++) {

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