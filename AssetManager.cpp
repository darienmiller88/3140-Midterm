#include "AssetManager.h"
#include <iostream>
#include <exception>

AssetManager::AssetManager(){
}

void AssetManager::addFont(const std::string &fontKey, const std::string &fileName){
	sf::Font font;

	if (textures.find(fontKey) != textures.end()) {
		throw std::exception(std::string("Key: " + fontKey + " already exists! Please enter a different key\n").c_str());
	}if (!font.loadFromFile(fileName)) {
		throw std::exception(std::string("File: " + fileName + " does not exist! Please enter a different file name\n").c_str());
	}

	fonts[fontKey] = std::move(font);
}

void AssetManager::addTexture(const std::string &textureKey, const std::string &fileName){
	sf::Texture texture;

	//if there already exists a key-value pair with the key the user is trying to enter, throw an exception stating that a different
	//key must be used. In the context of this program, overwriting the value of an existing pair with a new one with the same key is
	//undesirable.
	if (textures.find(textureKey) != textures.end()) {
		throw std::exception(std::string("Key: " + textureKey + " already exists! Please enter a different key\n").c_str());
	}else if (!texture.loadFromFile(fileName)) {
		throw std::exception(std::string("File: " + fileName + " does not exist! Please enter a different file name\n").c_str());
	}

	textures[textureKey] = std::move(texture);
}

/*
void AssetManager::unloadTextures(){
	textures.clear();
	sprites.clear();
}
*/

/*
void AssetManager::loadTextures(){
	//In order to reload the textures, we need to first check to see if the map of textures has already been cleared (unloaded)
	//before attempting to reload. This is done by simply checking to see if the size of the "textures" map is > 0.
	if (textures.size() > 0) {
		std::cout << "Cannot reload textures, as they already exist\n";
		return;
	}
		
	//if the map has been cleared, 
	for (auto &fileName : texturefileNames) {
		sf::Texture texture;

		if (!texture.loadFromFile(fileName.first)) {
			std::cout << "could not read from file: " << fileName.first << "\n";
			exit(1);
		}
		textures[fileName.first] = std::move(texture);
	}
}*/

const sf::Texture &AssetManager::getTexture(const std::string &textureKey) const{
	return textures.at(textureKey);
}

const sf::Font &AssetManager::getFont(const std::string &fontKey) const {
	return fonts.at(fontKey);
}