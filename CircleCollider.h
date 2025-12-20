#pragma once
#include "Collider.h"

class CircleCollider :
    public Collider
{
public:
    sf::Vector2f center;
    float radius;

    bool CollideWith(const Collider* other) const override;

    bool CollideWith(const BoxCollider* other) const override;
    bool CollideWith(const CircleCollider* other) const override;
};

