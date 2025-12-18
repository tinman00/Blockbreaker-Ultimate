#include "SceneManager.h"
#include "Engine.h"

namespace SceneManager
{
	void LoadScene(Scene* scene)
	{
		auto &objects = Engine::objects;
		objects.erase(
			std::remove_if(objects.begin(), objects.end(),
				[](GameObject* obj) {return !obj->dontDestroyOnLoad; }),
			objects.end()
		);
		for (auto obj : scene->objects) {
			objects.push_back(obj);
			obj->Start();
		}
	}
}