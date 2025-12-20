#include "BoxCollider.h"
#include "CircleCollider.h"
#include "General.h"
#include "Engine.h"

BoxCollider::BoxCollider(sf::Vector2f pos, sf::Vector2f size)
{
    this->position = pos;
    this->size = size;
}

bool BoxCollider::CollideWith(const Collider* other) const
{
    // 双重分派：other 是 const Collider*，现在 CollideWith 是 const 成员，可以被调用
    return other->CollideWith(this);
}

bool BoxCollider::CollideWith(const BoxCollider* other) const
{
    if (position.x >= other->size.x - size.x && position.x <= other->position.x + other->size.x &&
        position.y >= other->position.y - size.y && position.y <= other->position.y + other->size.y)
    {
        return true;
    }
    return false;
}

bool BoxCollider::CollideWith(const CircleCollider* other) const
{
    sf::Vector2f center = other->center;
    if(center.x >= position.x && center.x <= position.x + size.x &&
       center.y >= position.y - other->radius && center.y <= position.y + size.y + other->radius)
    {
        return true;
    }
    if (center.y >= position.y && center.y <= position.y + size.y &&
        center.x >= position.x - other->radius && center.x <= position.x + size.x + other->radius)
    {
        return true;
    }
    if ( DistanceSquared(center, sf::Vector2f(position.x, position.y)) <= other->radius * other->radius ||
         DistanceSquared(center, sf::Vector2f(position.x + size.x, position.y)) <= other->radius * other->radius ||
         DistanceSquared(center, sf::Vector2f(position.x, position.y + size.y)) <= other->radius * other->radius ||
         DistanceSquared(center, sf::Vector2f(position.x + size.x, position.y + size.y)) <= other->radius * other->radius)
    {
        return true;
    }
    return false;
}