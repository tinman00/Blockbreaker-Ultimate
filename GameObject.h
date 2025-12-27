#pragma once
#include <string>
#include <vector>
#include "SFML/System.hpp"

class Collider;

class GameObject
{
public:
	std::string name;
	bool dontDestroyOnLoad = false;
	sf::Vector2f position;
	sf::Vector2f size;
	Collider* collider;
	static int id;
	int thisid;
	bool isActive = true;
	GameObject* father;
	std::vector<GameObject*> children;

	bool GetActive();
	void SetActive(bool state);

	void SetCollider(Collider* collider);

	virtual void Start();
	virtual void UpdatePhysics();
	void SyncPosition();
	virtual void UpdateLogic();
	virtual void Render();
	virtual void OnCollision(Collider *other);
	virtual void OnDestroy();
	virtual ~GameObject() = default;
};

