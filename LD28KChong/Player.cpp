#include "Player.h"
#include "InputManager.h"
#include "TextureManager.h"

const float MAX_PLAYER_SPEED = 15;

Player::Player()
{

}

Player::~Player()
{

}

void Player::Load(sf::Vector2f position)
{
	mPlayerTexture = *TextureManager::LoadAndRetrieveTexture("Assets//player.png");
	mPlayerSprite.setTexture(mPlayerTexture);

	vPosition = position;
	mPlayerSprite.setPosition(vPosition);
}

void Player::Update(float delta)
{
	vVelocity = sf::Vector2f(0.0f, 0.0f);

	if(InputManager::Instance()->IsKeyDown(Inputs::LEFT))
	{
		vVelocity -= sf::Vector2f(MAX_PLAYER_SPEED * delta, 0.0f);
	}
	if(InputManager::Instance()->IsKeyDown(Inputs::RIGHT))
	{
		vVelocity += sf::Vector2f(MAX_PLAYER_SPEED * delta, 0.0f);
	}


	vPosition += vVelocity;

	mPlayerSprite.setPosition(vPosition);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(mPlayerSprite);
}