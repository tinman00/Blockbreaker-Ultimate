#pragma once
#include "Collider.h"

class BoxCollider :
    public Collider
{
public:
    sf::Vector2f position;
    sf::Vector2f size;

    BoxCollider(sf::Vector2f pos, sf::Vector2f size);

    bool IsCollideWith(const Collider* other) const override;

    bool IsCollideWith(const BoxCollider* other) const override;
    bool IsCollideWith(const CircleCollider* other) const override;

    sf::Vector2f CollideDirection(const Collider* other) const override;

    sf::Vector2f CollideDirection(const BoxCollider* other) const override;
    sf::Vector2f CollideDirection(const CircleCollider* other) const override;
};

