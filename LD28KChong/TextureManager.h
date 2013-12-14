#pragma once

#include <SFML\Graphics.hpp>

class TextureManager
{
private:
	//loads a texture and maps it to file location
	static std::map<std::string, sf::Texture*> mTextures;

	static std::map<std::string, sf::Font*> mFonts;

public:

	//loads the texture and returns a reference
	static sf::Texture* LoadAndRetrieveTexture(std::string file);

	//unloads the texture from the map
	//WARNING: pointers linked to this texture become unstable
	static void UnLoadTexture(std::string file);

	//loads the font and returns a reference
	static sf::Font* LoadAndRetrieveFont(std::string file);

	//unloads the font from the map
	static void UnloadFont(std::string file);

	static void DeleteAll();
};