#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Load(sf::Vector2f position);
	void Update(float delta);
	void Draw(sf::RenderWindow& window);

protected:
	sf::Texture mPlayerTexture;
	sf::Sprite mPlayerSprite;
};