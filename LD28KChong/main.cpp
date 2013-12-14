#include <SFML\Graphics.hpp>

#define SCREEN_WIDTH	1024
#define SCREEN_HEIGHT	768
#define BITS_PER_PIXEL	32
#define ANTIALIAS_LEVEL 4

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = ANTIALIAS_LEVEL;
	sf::RenderWindow Window = sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, BITS_PER_PIXEL), "LD28KChong",  sf::Style::Default, settings);

	// used to compute fps
	sf::Clock clock;
	sf::Time lElapsedTime = clock.getElapsedTime();
	sf::Time fpsTime = clock.getElapsedTime();				
	int numFrames = 0;

	sf::Event Event;

	while (Window.isOpen())
	{
		while (Window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				Window.close();
				break;
			}

			float lFrameTime = clock.getElapsedTime().asSeconds() - lElapsedTime.asSeconds();
			lElapsedTime = clock.getElapsedTime();

			if(lFrameTime >1)
				lFrameTime =0;

			Window.clear();
			Window.display();
		}
	}

	return 0;
}