#pragma once
#include "Collider.h"

class BoxCollider :
    public Collider
{
public:
    sf::Vector2f position;
    sf::Vector2f size;

    BoxCollider(sf::Vector2f pos, sf::Vector2f size);

    bool CollideWith(const Collider* other) const override;

    bool CollideWith(const BoxCollider* other) const override;
    bool CollideWith(const CircleCollider* other) const override;
};

