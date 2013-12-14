#include <SFML\Graphics.hpp>
#include <iostream>
#include "InputManager.h"
#include "Player.h"

#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	768
#define BITS_PER_PIXEL	32
#define ANTIALIAS_LEVEL 4

// You only get: one attack to kill this guy.
// If you don't kill this guy, you DIE. (And have to restart at the not-bonfire from Dark Souls)
// Use "cyberspace" art to cover up lack of art skill/animations

void DisplayFPS(int& numFrames, sf::Time& elapsedTime, sf::Time& fpsTime);

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIAS_LEVEL;
	sf::RenderWindow Window = sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BITS_PER_PIXEL), "LD28KChong",  sf::Style::Default, settings);

	sf::Clock clock;
	sf::Time lElapsedTime = clock.getElapsedTime();
	sf::Time fpsTime = clock.getElapsedTime();				
	int numFrames = 0;

	sf::Event Event;

	Player player;
	player.Load(sf::Vector2f(0,0));

	while (Window.isOpen())
	{
		while (Window.pollEvent(Event))
		{
			InputManager::Instance()->Update();
			InputManager::Instance()->ClearRecentlyPressedMouseButtons();

			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			case sf::Event::MouseButtonPressed:
				InputManager::Instance()->AddRecentlyPressedMouseButtons(Event);
				break;
			}
		}

		float lFrameTime = clock.getElapsedTime().asSeconds() - lElapsedTime.asSeconds();
		lElapsedTime = clock.getElapsedTime();

		DisplayFPS(numFrames, lElapsedTime, fpsTime);

		if(lFrameTime > 1)
			lFrameTime = 0;

		player.Update(lFrameTime);

		Window.clear();
		player.Draw(Window);
		Window.display();		
	}

	return 0;
}

void DisplayFPS(int& numFrames, sf::Time& elapsedTime, sf::Time& fpsTime)
{
	// Calculate/Display FPS
	numFrames++;
	if (elapsedTime.asSeconds() >= fpsTime.asSeconds() + 1.0f) 
	{
		std::cout << "fps = " << numFrames << "\n";
		fpsTime = elapsedTime;
		numFrames = 0;
	}
}