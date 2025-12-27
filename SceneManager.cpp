#include "SceneManager.h"
#include "Base.h"
#include "UI.h"
#include <vector>
#include <string>
#include <iostream>

namespace SceneManager
{
	void LoadScene(Scene* scene)
	{
		Engine::window->setSize({ static_cast<unsigned int>(scene->windowWidth),
			static_cast<unsigned int>(scene->windowHeight) });
		Engine::resetViewport();
		auto& objects = Engine::objects;
		std::vector<std::string> keyToErase;
		for (auto& [key, obj] : objects) {
			if (!obj->dontDestroyOnLoad) {
				keyToErase.push_back(key);
			}
		}
		for (auto key : keyToErase) {
			//std::cout << "Key: \"" << key << "\" erased." << std::endl;
			auto obj = objects[key];
			delete obj;
			obj = nullptr;
			objects.erase(key);
		}
		for (auto& [key, obj] : scene->objects) {
			if (objects.find(key) == objects.end()) {
				objects[key] = obj;
			}
			else {
				scene->objects.erase(key);
			}
		}
		auto& uis = Engine::uis;
		uis.erase(std::remove_if(uis.begin(), uis.end(), [](UI* ui) {return !ui->dontDestroyOnLoad; }), uis.end());
		for (auto& [key, obj] : scene->objects) {
			obj->Start();
			if (auto ui = dynamic_cast<UI*>(obj)) {
				uis.push_back(ui);
			}
		}
		std::sort(uis.begin(), uis.end(), [](UI* ui1, UI* ui2) { return ui1->layer < ui2->layer; });
	}
}