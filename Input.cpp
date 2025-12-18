#include "Input.h"
#include "SFML/Window/Keyboard.hpp"

namespace Input
{
	std::unordered_map<int, sf::Keyboard::Key> KeyMap;

	bool GetKeydown(Binds bind)
	{
		return sf::Keyboard::isKeyPressed(KeyMap[static_cast<int>(bind)]);
	}

	void ResetKeyMap()
	{
		KeyMap[static_cast<int>(Binds::MoveLeft)] = sf::Keyboard::Key::A;
		KeyMap[static_cast<int>(Binds::MoveRight)] = sf::Keyboard::Key::D;
		KeyMap[static_cast<int>(Binds::Fire)] = sf::Keyboard::Key::Space;
		KeyMap[static_cast<int>(Binds::Pause)] = sf::Keyboard::Key::P;
		KeyMap[static_cast<int>(Binds::Menu)] = sf::Keyboard::Key::Escape;
		KeyMap[static_cast<int>(Binds::SpeedUp)] = sf::Keyboard::Key::LShift;
	}
}