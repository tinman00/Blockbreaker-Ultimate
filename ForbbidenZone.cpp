#include "ForbbidenZone.h"
#include "BasicColliders.h"
#include "BasicObjects.h"

ForbbidenZone::ForbbidenZone(sf::Vector2f pos, sf::Vector2f siz)
{
	this->SetCollider(new BoxCollider(pos, siz));
	this->position = pos;
}

void ForbbidenZone::OnCollision(Collider* other)
{
	if (dynamic_cast<Ball*>(other->owner)) {
		Engine::Destroy(other->owner);
	}
}
