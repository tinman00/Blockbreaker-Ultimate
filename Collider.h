#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class BoxCollider;
class CircleCollider;
class Collider
{
public:
    sf::Vector2f position;
    sf::Vector2f velocity;

    virtual bool CollideWith(const Collider* other) const;

    virtual bool CollideWith(const BoxCollider* other) const;
    virtual bool CollideWith(const CircleCollider* other) const;
};

