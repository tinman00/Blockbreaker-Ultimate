#include "Base.h"
#include "TestScene.h"
#include "TestScene2.h"
#include "Button.h"
#include "BoxCollider.h"
#include "Text.h"

TestScene::TestScene()
{
	std::cout << "Loading test scene 1" << std::endl;
	CreateObject(
		"Button 1",
		new Button(
			{ 400, 250 },
			{ 500, 200 },
			2,
			[]() {
				std::cout << "Clicking button 1" << std::endl;
				SceneManager::LoadScene(new TestScene2());
			}
		));

	auto txt = CreateObject("Text", new Text({400,250}, u8"ÈË£¬¹ýÀ´", sf::Color(255, 127, 63), "Deng.ttf", 32));
	CreateObject(
		"Button 2",
		new Button(
			{ 800, 350 },
			{ 400, 200 },
			2,
			[]() {
				//std::cout << "Finding \"Button 1\" to click it" << std::endl;
				//Engine::GetObject<Button>("Button 1")->OnClick();
				//std::cout << "Destroying GameObject \"Text\"." << std::endl;
				//Engine::Destroy(Engine::GetObject<GameObject>("Text"));
				std::cout << "Set GameObject \"Text\" inactive." << std::endl;
				Engine::GetObject<GameObject>("Text")->SetActive(false);
			}
		),
		txt
	);
	objects["Button 1"]->collider->CollideWith(objects["Button 2"]->collider);
}
