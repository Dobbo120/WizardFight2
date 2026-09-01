#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class TextureHolder {
	//This is lifted from "Beginning C++ Game Programming" Third Edition by John Horton
private:
	std::map<String, Texture> m_Textures;
	//map to hold textures according to their filenames
	static TextureHolder* m_s_Instance;
	//There should only be one TextureHolder
public:
	TextureHolder();

	static Texture& GetTexture(String const& filename);
	//Returns a texture memory location reference
};

#endif