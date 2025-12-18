#include "CircleCollider.h"
#include "General.h"
#include "BoxCollider.h"

bool CircleCollider::CollideWith(const Collider* other) const
{
    return other->CollideWith(this);
}

bool CircleCollider::CollideWith(const BoxCollider* other) const
{
    return other->CollideWith(this);
}

bool CircleCollider::CollideWith(const CircleCollider* other) const
{
    return DistanceSquared(this->center, other->center) <= (this->radius + other->radius) * (this->radius + other->radius);
}