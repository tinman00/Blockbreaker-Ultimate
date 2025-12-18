#pragma once
#include "GameObject.h"
#include <vector>
class GameObject;

class Scene
{
public:
	std::vector<GameObject*> objects;

	Scene();
	virtual ~Scene() = default;
};

