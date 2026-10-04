
#include <SFML/Graphics.hpp>

using namespace sf;

class Background : public Drawable, public Transformable
{
public:
	
	
	bool load(const std::filesystem::path& tileset, Vector2u tileSize, float scale);
	//lifted from "Beginning C++ Game Programming" Third Edition by John Horton


private:


	void draw(RenderTarget& target, RenderStates states) const override;

	VertexArray m_vertices;
	Texture m_tileset;
	const unsigned int xTiles = 30;
	const unsigned int yTiles = 20;
};
