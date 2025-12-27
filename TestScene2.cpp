#include "TestScene2.h"
#include "TestScene3.h"
#include "TestScene.h"
#include "Button.h"
#include <iostream>
#include "SceneManager.h"
#include "Text.h"
#include "SFML/System.hpp"

TestScene2::TestScene2()
{

	std::cout << "Loading test scene 2" << std::endl;
	CreateObject(
		"Button 1",
		new Button(
			{ 750, 300 },
			{ 240, 200 },
			2,
			[]() {
				std::cout << "Clicking button 2" << std::endl;
				SceneManager::LoadScene(new TestScene3());
			}
		));
	CreateObject("Text",new Text({ 750, 300 }, u8"Õâ¸ö¸øÄã", sf::Color(127, 127, 255), "Deng.ttf", 32, 1));
}
