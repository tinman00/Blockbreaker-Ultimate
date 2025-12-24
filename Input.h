#pragma once
#include <unordered_map>
#include "SFML/Window/Keyboard.hpp"

namespace Input
{
	enum class Binds {
		MoveLeft = 0,
		MoveRight = 1,
		Fire = 2,
		Pause = 3,
		Menu = 4,
		SpeedUp = 5,
	};
	extern std::unordered_map<int, sf::Keyboard::Key> KeyMap;
	bool GetKeydown(Binds bind);
	float GetHorizontal();
	void ResetKeyMap();
};