#include "TestScene3.h"
#include "TestScene.h"
#include "Button.h"
#include <iostream>
#include "SceneManager.h"
#include "Text.h"
#include "SFML/System.hpp"

TestScene3::TestScene3()
{

	std::cout << "Loading test scene 3" << std::endl;
	objects.push_back(new Button(
		{ 750, 300 },
		{ 240, 200 },
		2,
		[]() {
			std::cout << "Clicking button 3" << std::endl;
			SceneManager::LoadScene(new TestScene());
		}
	));
	objects.push_back(new Text({ 750, 300 }, u8"好了，出去", sf::Color(127, 127, 255), "Deng.ttf", 32));
}
