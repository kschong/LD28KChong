#pragma once

#include <SFML\Graphics.hpp>

class GameObject 
{
public:
	enum GameObjectType 
	{
		PLAYER, ENEMY_BASIC, ENEMY_WARP
	};

	GameObject() {};
	~GameObject() {};

	GameObjectType getType() { return mType; }
	sf::Vector2f getPosition() { return vPosition; }
	sf::Vector2f getVelocity() { return vVelocity; }
	float getHealth() {return fHealth; }
	bool getIsDead() { return bIsDead; }

	virtual void Load(sf::Vector2f position) {};
	virtual void Update(float delta) {};
	virtual void Draw(sf::RenderWindow& window) {};

protected:
	GameObjectType mType;

	sf::Vector2f vPosition;
	sf::Vector2f vVelocity;
	
	float fHealth;
	bool bIsDead;
};