#pragma once
#include "GameObject.h"
#include <vector>
#include <unordered_map>
#include <iostream>
class GameObject;

class Scene
{
public:
	float windowWidth = 1920, windowHeight = 1080;
	std::unordered_map<std::string, GameObject*> objects;

	GameObject* CreateObject(std::string name, GameObject* obj, GameObject* father = nullptr);
    template <typename T> T* GetObject(std::string name)
    {
        if (objects.find(name) == objects.end()) {
            std::cerr << "Error: Can not find GameObject with name \"" << "\" " << std::endl;
            return nullptr;
        }
        if (T* ptr = dynamic_cast<T*> (objects[name])) {
            return ptr;
        }
        else {
            std::cerr << "Error: GameObject \"" << "\" doesn't have target type." << std::endl;
            return nullptr;
        }
    }
	Scene();
	virtual ~Scene() = default;
};

