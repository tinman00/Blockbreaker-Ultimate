#pragma once

class Collider;

class GameObject
{
public:
	bool dontDestroyOnLoad = false;
	Collider* collider;

	virtual void Start();
	virtual void UpdatePhysics();
	virtual void UpdateLogic();
	virtual void Render();
	virtual void OnCollision(Collider *other);
	virtual ~GameObject() = default;
};

