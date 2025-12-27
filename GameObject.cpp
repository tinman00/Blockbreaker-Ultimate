#include "GameObject.h"
#include "Collider.h"
#include "Engine.h"
#include "SFML/Graphics.hpp"

int GameObject::id = 0;

bool GameObject::GetActive()
{
	if (father) {
		return isActive && father->GetActive();
	}
	else {
		return isActive;
	}
}

void GameObject::SetActive(bool state)
{
	isActive = state;
}

void GameObject::SetCollider(Collider* collider)
{
	this->collider = collider;
	collider->owner = this;
}

void GameObject::Start()
{

}

void GameObject::UpdatePhysics()
{

}

void GameObject::SyncPosition()
{
	position = collider->position;
}

void GameObject::UpdateLogic()
{

}

void GameObject::Render()
{
	
}

void GameObject::OnCollision(Collider* other)
{

}

void GameObject::OnDestroy()
{

}
