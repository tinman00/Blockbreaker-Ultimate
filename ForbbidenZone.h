#pragma once
#include "GameObject.h"
class ForbbidenZone :
    public GameObject
{
public:
    ForbbidenZone(sf::Vector2f pos, sf::Vector2f siz);
	void OnCollision(Collider* other) override;
};

