#include "TextureManager.h"
#include <iostream>

std::map<std::string, sf::Texture*> TextureManager::mTextures;
std::map<std::string, sf::Font*> TextureManager::mFonts;

sf::Texture* TextureManager::LoadAndRetrieveTexture(std::string file)
{
	sf::Texture* lTexture;
	if((TextureManager::mTextures.find(file) == TextureManager::mTextures.end()))
	{
		lTexture= new sf::Texture();
		lTexture->loadFromFile(file);
		TextureManager::mTextures.insert(std::pair<std::string,sf::Texture*>(file,lTexture));
	}

	return TextureManager::mTextures[file];

}

void TextureManager::UnLoadTexture(std::string file)
{
	if(TextureManager::mTextures.find(file) == TextureManager::mTextures.end())
	{		
		delete TextureManager::mTextures[file];
		TextureManager::mTextures.erase(TextureManager::mTextures.find(file));
	}
}

//loads the font and returns a reference
sf::Font* TextureManager::LoadAndRetrieveFont(std::string file)
{
	sf::Font* lFont;
	if((TextureManager::mFonts.find(file) == TextureManager::mFonts.end()))
	{
		lFont = new sf::Font();
		lFont->loadFromFile(file);
		TextureManager::mFonts.insert(std::pair<std::string,sf::Font*>(file,lFont));
	}

	return TextureManager::mFonts[file];
}

//unloads the font from the map
void TextureManager::UnloadFont(std::string file)
{
	if(TextureManager::mFonts.find(file) == TextureManager::mFonts.end())
	{		
		delete TextureManager::mFonts[file];
		TextureManager::mFonts.erase(TextureManager::mFonts.find(file));
	}
}

void TextureManager::DeleteAll() {

	for (std::map<std::string, sf::Texture*>::iterator it = mTextures.begin(); it != mTextures.end(); it++) {
		delete it->second;
	}

	for (std::map<std::string, sf::Font*>::iterator it = mFonts.begin(); it != mFonts.end(); it++) {
		delete it->second;
	}
}