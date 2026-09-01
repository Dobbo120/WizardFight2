#include "TextureHolder.h"
#include <assert.h>
#include <iostream>

//TextureHolder is not yet called in the code, I coded my own method of loading the background and I am in the process of changing to this more memory efficient Texture Management system

TextureHolder* TextureHolder::m_s_Instance = nullptr;
//A pointer to what should be a single TextureHolder is created, but since TextureHolder is not yet initiated, it is a nullptr.
TextureHolder::TextureHolder() {
	// Making the TextureHolder a singleton
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(String const& filename) {
	//Returns a reference for the texture when given a filepath.  This allows the texture to only exist once in memory within a map inside of the singleton TextureHolder

	//Auto automatically figures out the types of m_Textures
	auto& m = m_s_Instance->m_Textures;

	auto keyValuePair = m.find(filename);
	//if the keyValuePair exists in the map it'll return the texture using the filepath
	if (keyValuePair != m.end()) {
	
		return keyValuePair->second;
	
	}
	else {
		auto& texture = m[filename];
		//If the filename isn't already in the map, a texture object is created in the map linked to the filename

		std::filesystem::path filenamePath(filename);
		//Having to convert these strings to paths is stupid

		if (!texture.loadFromFile(filenamePath)) {
			//And this loads the texture into the map 
			std::cout << "Something went wrong.  Check if you mistyped " << &filename;

		}
		//And everything going right, this returns the texture
		return texture;
	}
}