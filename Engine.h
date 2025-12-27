#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <list>
#include "SFML/Graphics.hpp"

class GameObject;
class UI;
class Camera;

namespace Engine
{
	class EngineTime {
	public:
	};
	extern sf::RenderWindow *window;

	extern std::unordered_map<std::string, GameObject*> objects;
	extern std::vector<UI*> uis;
	extern std::vector<Camera*> cameras;

	extern std::vector<GameObject*> toDelete;

	extern sf::Clock gameClock;
	extern float lastUpdateTime;
	extern float stashedUpdateTime;
	extern float deltaTime;
	extern float fixedDeltaTime;
	extern int currentObjectID;
	extern bool isPaused;

	void resetViewport();
	void Initialize();
	void LazyUpdate();
	void Update();
	void UpdatePhysics();
	void UpdateGameLogic();
	void Render();
	void Run();
    void Destroy(GameObject* obj);
	void Delete(GameObject* obj);
	void ClearBin();
	void TogglePause();
	int GetNextObjectID();
	int32_t GetTimeMillis();

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
}