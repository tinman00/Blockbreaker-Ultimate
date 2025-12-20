#include "TestScene.h"
#include "TestScene2.h"
#include "Button.h"
#include "BoxCollider.h"
#include "Text.h"
#include "SceneManager.h"
#include "SFML/System.hpp"
#include <iostream>

TestScene::TestScene()
{
	std::cout << "Loading test scene 1" << std::endl;
	objects.push_back(new Button(
		{ 400, 250 },
		{ 300, 200 },
		2,
		[]() {
			std::cout << "Clicking button 1" << std::endl;
			SceneManager::LoadScene(new TestScene2());
		}
	));
	objects.push_back(new Button(
		{ 800, 350 },
		{ 400, 200 },
		2,
		[]() {
			std::cout << "Clicking button 2" << std::endl;
			SceneManager::LoadScene(new TestScene2());
		}
	));
	std::cout << objects[0]->collider->CollideWith(objects[1]->collider) << std::endl;
	objects.push_back(new Text({ 300,300 }, L"ÈË£¬¹ýÀ´", sf::Color(255, 127, 63), "Deng.ttf", 32));
}
