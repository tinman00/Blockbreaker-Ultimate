#include "CircleCollider.h"
#include "General.h"
#include "BoxCollider.h"

CircleCollider::CircleCollider(sf::Vector2f pos, float radius)
{
    this->position = pos;
    this->radius = radius;
}

bool CircleCollider::IsCollideWith(const Collider* other) const
{
    return other->IsCollideWith(this);
}

bool CircleCollider::IsCollideWith(const BoxCollider* other) const
{
    return other->IsCollideWith(this);
}

bool CircleCollider::IsCollideWith(const CircleCollider* other) const
{
    return DistanceSquared(this->position, other->position) <= (this->radius + other->radius) * (this->radius + other->radius);
}

sf::Vector2f CircleCollider::CollideDirection(const Collider* other) const
{
    return -other->CollideDirection(this);
}

sf::Vector2f CircleCollider::CollideDirection(const CircleCollider* other) const
{
    return Normalize(position - other->position);
}

sf::Vector2f CircleCollider::CollideDirection(const BoxCollider* other) const
{
    return -other->CollideDirection(this);
}