#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class TextureHolder {
private:
	std::map<String, Texture> m_Textures;

	static TextureHolder* m_s_Instance;

public:
	TextureHolder();

	static Texture& GetTexture(String const& filename);
};

#endif