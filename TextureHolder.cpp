#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(String const& filename) {

	auto& m = m_s_Instance->m_Textures;

	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end()) {
	
		return keyValuePair->second;
	
	}
	else {
		auto& texture = m[filename];

		std::filesystem::path filenamePath(filename);
		//Having to convert these strings to paths is stupid

		texture.loadFromFile(filenamePath);

		return texture;
	}
}