#include "CircleCollider.h"
#include "General.h"
#include "BoxCollider.h"

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
    return DistanceSquared(this->center, other->center) <= (this->radius + other->radius) * (this->radius + other->radius);
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