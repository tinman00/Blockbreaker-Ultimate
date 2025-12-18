#include "TestScene.h"
#include "Button.h"
#include "BoxCollider.h"
#include "Text.h"
#include <iostream>

TestScene::TestScene()
{
	objects.push_back(new Button({ 400  , 250 }, { 300, 200 }));
	objects.push_back(new Button({ 800, 350 }, { 400, 200 }));
	objects.push_back(new Text({ 400,250 }, "Hello world", sf::Color(0,0,0), "Arial.ttf", 24));
	std::cout << objects[0]->collider->CollideWith(objects[1]->collider) << std::endl;

}
