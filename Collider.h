#pragma once
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "GameObject.h"

class GameObject;
class BoxCollider;
class CircleCollider;
class Collider
{
public:
    GameObject* owner;

    sf::Vector2f position;
    sf::Vector2f velocity;
    bool isFixed = false;

    virtual bool IsCollideWith(const Collider* other) const;

    virtual bool IsCollideWith(const BoxCollider* other) const;
    virtual bool IsCollideWith(const CircleCollider* other) const;

    virtual sf::Vector2f CollideDirection(const Collider* other) const;

    virtual sf::Vector2f CollideDirection(const BoxCollider* other) const;
    virtual sf::Vector2f CollideDirection(const CircleCollider* other) const;

    // If A collides with B, then A.CollideDirection(B) will be parallel with the normal line.
    // And it points from B to A. 
	// And it is Normalized.

    void CollideWith(Collider* other);

    void MoveStep();
};

