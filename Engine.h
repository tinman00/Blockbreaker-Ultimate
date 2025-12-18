#pragma once
#include <vector>
#include "SFML/Graphics.hpp"

class GameObject;
class Camera;

namespace Engine
{
	class EngineTime {
	public:
	};
	void Initialize();
	void Update();
	void UpdatePhysics();
	void UpdateGameLogic();
	void Render();
	void Run();
	extern sf::RenderWindow *window;

	extern std::vector<GameObject*> objects;
	extern std::vector<Camera*> cameras;
}