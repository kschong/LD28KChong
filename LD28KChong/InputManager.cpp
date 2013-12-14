#include "InputManager.h"

InputManager::~InputManager()
{

}

InputManager* InputManager::Instance()
{
	static InputManager instance;

	return &instance;
}

sf::Keyboard::Key InputManager::GetInputKey(Inputs input)
{
	return (sf::Keyboard::Key) mInputMap[input];
}

sf::Mouse::Button InputManager::GetMouseInputButton(Inputs input)
{
	return (sf::Mouse::Button) mMouseInputMap[input];
}

bool InputManager::IsKeyPressed(Inputs input)
{
	for each(sf::Keyboard::Key key in mKeysRecentlyPressed)
	{
		if (key == GetInputKey(input)) 
		{
			mKeysRecentlyPressed.erase(key);
			return true;
		}
	}

	return false;
}

bool InputManager::IsKeyDown(Inputs input)
{
	return sf::Keyboard::isKeyPressed(GetInputKey(input));
}

bool InputManager::IsKeyUp(Inputs input)
{
	return !sf::Keyboard::isKeyPressed(GetInputKey(input));
}

void InputManager::Update()
{
	std::map<int, int>::iterator it;
	bool keyDown;
	bool needsUpState;
	sf::Keyboard::Key key;

	for(it = mInputMap.begin(); it != mInputMap.end(); it++) 
	{
		key = (sf::Keyboard::Key)it->second;
		keyDown = sf::Keyboard::isKeyPressed(key);
		needsUpState = (mKeysNeedUpState.find(key) != mKeysNeedUpState.end());

		if (keyDown && !needsUpState) {
			mKeysRecentlyPressed.insert(key);
			mKeysNeedUpState.insert(key);
		}
		else if (!keyDown) {
			mKeysNeedUpState.erase(key);
			mKeysRecentlyPressed.erase(key);
		}
	}
}

bool InputManager::IsMouseButtonPressed(Inputs input)
{
	for each(sf::Mouse::Button button in mMouseButtonsRecentlyPressed)
	{
		if(button == GetMouseInputButton(input))
			return true;
	}

	return false;
}

bool InputManager::IsMouseButtonDown(Inputs input)
{
	return sf::Mouse::isButtonPressed(GetMouseInputButton(input));
}

bool InputManager::IsMouseButtonUp(Inputs input)
{
	return !sf::Mouse::isButtonPressed(GetMouseInputButton(input));
}

void InputManager::ClearRecentlyPressedMouseButtons()
{
	mMouseButtonsRecentlyPressed.clear();	
}

void InputManager::AddRecentlyPressedMouseButtons(sf::Event event)
{
	if(event.type == sf::Event::MouseButtonPressed)
	{
		mMouseButtonsRecentlyPressed.insert(event.mouseButton.button);
	}
}