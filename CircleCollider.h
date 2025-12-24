#pragma once
#include "Collider.h"

class CircleCollider :
    public Collider
{
public:
    float radius;

    CircleCollider(sf::Vector2f pos, float radius);

    bool IsCollideWith(const Collider* other) const override;

    bool IsCollideWith(const BoxCollider* other) const override;
    bool IsCollideWith(const CircleCollider* other) const override;


    sf::Vector2f CollideDirection(const Collider* other) const override;

    sf::Vector2f CollideDirection(const BoxCollider* other) const override;
    sf::Vector2f CollideDirection(const CircleCollider* other) const override;


};

