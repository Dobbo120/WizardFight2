#include "Background.h"
#include "TextureHolder.h"

class Background : public Drawable, public Transformable
{
	
public:
	bool load(const String& tileset, Vector2u tileSize, unsigned int width, unsigned int height) {
		// This code is lifted, with small modifications from "Beginning C++ Game Programming" Third edition by John Horton.
		// "Quads" is no longer a valid PrimitiveType, requiring the use of Triangles, for which I am going to modify the code according to 
		// the SFML documentation on using a VertexArray to create a TileMap

		m_tileset = TextureHolder::GetTexture(tileset);
		
		m_vertices.setPrimitiveType(PrimitiveType::Triangles);
		m_vertices.resize(width*height*6);

		for (unsigned int i = 0; i < 29; ++i) {
			for (unsigned int j = 0; j < 19; ++j) {
				level[i * j + i] = rand() % 10;
			}
		}

		for (unsigned int i = 0; i < width; ++i) {
			for (unsigned int j = 0; j < height; ++j) {
				const int tileNumber = level[i * j * width];

				const int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				const int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				Vertex* triangles = &m_vertices[(i * j * width) * 6];

				triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				triangles[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				triangles[2].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
				triangles[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
				triangles[4].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				triangles[5].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

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

		//const int TILE_SIZE = 32;
		//const int TILE_TYPES = 100;
		//const int VERTS_NUM = 6;
		//Verts in Quad will have to be changed to 6, and I may change it's name since it will instead by two triangles next to each other to
		//create a square

		//int worldWidth = background.size.x / TILE_SIZE;
		//int worldHeight = background.size.y / TILE_SIZE;

		//rVA.setPrimitiveType(PrimitiveType::Triangles);

		//rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

		//int currentVertex = 0;

		//for (int w = 0; w < worldWidth; w++) {
			//for (int h = 0; h < worldHeight; h++) {
				//This code needs to be changed to reflect that Quads no longer exist as a PrimitiveType and it will instead be six Vertices for two triangles
				//This will also mean changing the texture positions of the VertexArray
				//rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);

				//rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

				//rVA[currentVertex + 2].position = Vector2f(w * TILE_SIZE, (h * TILE_SIZE)+TILE_SIZE);

				//rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

				//currentVertex += VERTS_NUM;

			//}
		//}

		//return TILE_SIZE;

	}
private:
	
	void draw(RenderTarget& target, RenderStates states) const override {
		states.transform *= getTransform();

		states.texture = &m_tileset;

		target.draw(m_vertices, states);
	}

	Texture m_tileset;
	VertexArray m_vertices;
	std::array<int, 30 * 20> level = { 0 };
};