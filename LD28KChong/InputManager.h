#pragma once

#pragma warning(disable : 4482)

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <set>

//input manager
enum Inputs
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ACTION,
	COLLECTOR_BEAM,
	REPULSOR_WAVE,
	LASER,
	JUMPER_CABLES,
	FIRE_LEFT,
	FIRE_RIGHT,
	SWITCH_RESOURCE,
	PREVIOUS_WEAP,
	REFUEL,
	REPLAY_MESSAGE,
	TOGGLE_NEBULA,
	TOGGLE_FULLSCREEN,
	TOGGLE_SLOWMO,
	PAUSE_GAME
};

// Singleton which manages input.
class InputManager
{
private: 

	InputManager()
	{
		mInputMap[Inputs::UP] = (int)(sf::Keyboard::W);
		mInputMap[Inputs::DOWN] = (int)(sf::Keyboard::S);
		mInputMap[Inputs::LEFT] = (int)(sf::Keyboard::A);
		mInputMap[Inputs::RIGHT] = (int)(sf::Keyboard::D);
		mInputMap[Inputs::ACTION] = (int)(sf::Keyboard::Space);
		mMouseInputMap[Inputs::FIRE_LEFT] = (int)(sf::Mouse::Button::Left);
		mMouseInputMap[Inputs::FIRE_RIGHT] = (int)(sf::Mouse::Button::Right);

		mInputMap[Inputs::PAUSE_GAME]	   = (int)(sf::Keyboard::Escape);

		mInputMap[Inputs::TOGGLE_FULLSCREEN]	   = (int)(sf::Keyboard::F11);
	}

	// Copy constructor and assignment operator are made private.
	InputManager(const InputManager &);
	InputManager& operator=(const InputManager &);

	std::map<int, int> mInputMap;
	std::map<int, int> mMouseInputMap;

	std::set<sf::Keyboard::Key> mKeysRecentlyPressed;
	std::set<sf::Keyboard::Key> mKeysNeedUpState;
	std::set<sf::Mouse::Button> mMouseButtonsRecentlyPressed;

public:
	~InputManager();

	static InputManager* Instance();

	sf::Keyboard::Key GetInputKey(Inputs input);
	sf::Mouse::Button GetMouseInputButton(Inputs input);

	bool IsKeyPressed(Inputs input);
	bool IsKeyDown(Inputs input);
	bool IsKeyUp(Inputs input);

	bool IsMouseButtonPressed(Inputs input);
	bool IsMouseButtonDown(Inputs input);
	bool IsMouseButtonUp(Inputs input);

	void ClearRecentlyPressedMouseButtons();
	void AddRecentlyPressedMouseButtons(sf::Event event);

	void Update();
};