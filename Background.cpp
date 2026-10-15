#include "Background.h"
#include <iostream>

using namespace sf;


Texture m_tileset;
VertexArray m_vertices;

const unsigned int xTiles = 30;
const unsigned int yTiles = 20;

std::array<int, xTiles* yTiles > level = { 0 };

Background::Background() {
	startPosX = 0;
	startPosY = 0;
}

bool Background::load(const std::filesystem::path& tileset, Vector2u tileSize, float scale) {
	// This code only has minor deviations from the SFML tutorial for a TileMap from 2026
	
	if (!m_tileset.loadFromFile(tileset)) {
		std::cout << "Background did not load";
	}
	

	int tileWidth = tileSize.x * scale;
	int tileHeight = tileSize.y * scale;
	//The tile textures are scaled
	
	int offScreen = 3;
	//How many tiles are offscreen in any direction
		
	m_vertices.setPrimitiveType(PrimitiveType::Triangles);
	//std::cout << xTiles << " ";
	//std::cout << yTiles;
	m_vertices.resize(xTiles*yTiles*6);

	for (unsigned int i = 0; i < xTiles*yTiles; ++i) {
		
			level[i] = rand() % 100;
			//The textures are picked randomly
	}
	

	for (unsigned int i = 0; i < xTiles; ++i) {
		for (unsigned int j = 0; j < yTiles; ++j) {
			const int tileNumber = level[i + j * xTiles];
			//This code is lifted directly from the SFML TileMap Tutorial in 2026, unless I explain something else.
			//Each tile is composed of two triangles

			//std::cout << " ";
			//std::cout << tileNumber;

			const int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			const int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);
			//It is really funny that this lifted code from the SFML TileMap tutorial works perfectly

			Vertex* triangles = &m_vertices[(i + j * xTiles) * 6];

			triangles[0].position = sf::Vector2f((i - offScreen) * tileWidth + startPosX, (j - offScreen) * tileHeight + startPosY);
			triangles[1].position = sf::Vector2f((i - offScreen + 1) * tileWidth + startPosX, (j - offScreen) * tileHeight + startPosY);
			triangles[2].position = sf::Vector2f((i- offScreen) * tileWidth + startPosX, (j - offScreen + 1) * tileHeight + startPosY);
			triangles[3].position = sf::Vector2f((i - offScreen) * tileWidth + startPosX, (j - offScreen + 1) * tileHeight + startPosY);
			triangles[4].position = sf::Vector2f((i - offScreen + 1) * tileWidth + startPosX, (j - offScreen) * tileHeight + startPosY);
			triangles[5].position = sf::Vector2f((i - offScreen + 1) * tileWidth + startPosX, (j - offScreen + 1) * tileHeight + startPosY);
			//This sets the corners of the Triangles, the offscreen allows some tiles to exist offscreen

			// define the 6 matching texture coordinates
			triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			triangles[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			triangles[2].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			triangles[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			triangles[4].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			triangles[5].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
		}
	}
	return true;
}

	
void Background::draw(RenderTarget& target, RenderStates states) const{
	//This is also lifted from the SFML TileMap tutorial in 2026
	states.transform *= getTransform();

	states.texture = &m_tileset;

	target.draw(m_vertices, states);
}

void Background::move(int dir, Vector2u tileSize, float scale) {
	startPosX += 1;
	startPosY += 1;
	//This should all be defined above, and I could probably make a separate function for repositioning the background?
	int offScreen = 3;

	int tileWidth = tileSize.x * scale;
	int tileHeight = tileSize.y * scale;

	for (unsigned int i = 0; i < xTiles; ++i) {
		for (unsigned int j = 0; j < yTiles; ++j) {
			const int tileNumber = level[i + j * xTiles];

			Vertex* triangles = &m_vertices[(i + j * xTiles) * 6];

			triangles[0].position = sf::Vector2f((i - offScreen) * tileWidth + startPosX, (j - offScreen) * tileHeight + startPosY);
			triangles[1].position = sf::Vector2f((i - offScreen + 1) * tileWidth + startPosX, (j - offScreen) * tileHeight + startPosY);
			triangles[2].position = sf::Vector2f((i - offScreen) * tileWidth + startPosX, (j - offScreen + 1) * tileHeight + startPosY);
			triangles[3].position = sf::Vector2f((i - offScreen) * tileWidth + startPosX, (j - offScreen + 1) * tileHeight + startPosY);
			triangles[4].position = sf::Vector2f((i - offScreen + 1) * tileWidth + startPosX, (j - offScreen) * tileHeight + startPosY);
			triangles[5].position = sf::Vector2f((i - offScreen + 1) * tileWidth + startPosX, (j - offScreen + 1) * tileHeight + startPosY);
		}
	}
}

	
