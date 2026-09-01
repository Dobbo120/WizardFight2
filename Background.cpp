#include "Background.h"

int createBackground(VertexArray& rVA, IntRect background) {
	// This code is lifted, with small modifications from "Beginning C++ Game Programming" Third edition by John Horton.
	// "Quads" is no longer a valid PrimitiveType, requiring the use of Triangles, for which I am going to modify the code according to 
	// the SFML documentation on using a VertexArray to create a TileMap
	const int TILE_SIZE = 32;
	const int TILE_TYPES = 100;
	const int VERTS_IN_QUAD = 4;
	//Verts in Quad will have to be changed to 6, and I may change it's name since it will instead by two triangles next to each other to
	//create a square

	int worldWidth = background.size.x / TILE_SIZE;
	int worldHeight = background.size.y / TILE_SIZE;

	rVA.setPrimitiveType(PrimitiveType::Triangles);

	rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

	int currentVertex = 0;

	for (int w = 0; w < worldWidth; w++) {
		for (int h = 0; h < worldHeight; h++) {
			//This code needs to be changed to reflect that Quads no longer exist as a PrimitiveType and it will instead be six Vertices for two triangles
			//This will also mean changing the texture positions of the VertexArray
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);

			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);

			rVA[currentVertex + 2].position = Vector2f(w * TILE_SIZE, (h * TILE_SIZE)+TILE_SIZE);

			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);

			currentVertex += VERTS_IN_QUAD;

		}
	}

	return TILE_SIZE;

}