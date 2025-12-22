#include "BoxCollider.h"
#include "CircleCollider.h"
#include "General.h"
#include "Engine.h"

BoxCollider::BoxCollider(sf::Vector2f pos, sf::Vector2f size)
{
    this->position = pos;
    this->size = size;
}

bool BoxCollider::IsCollideWith(const Collider* other) const
{
    return other->IsCollideWith(this);
}

bool BoxCollider::IsCollideWith(const BoxCollider* other) const
{
    if (position.x >= other->size.x - size.x && position.x <= other->position.x + other->size.x &&
        position.y >= other->position.y - size.y && position.y <= other->position.y + other->size.y)
    {
        return true;
    }
    return false;
}

bool BoxCollider::IsCollideWith(const CircleCollider* other) const
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

sf::Vector2f BoxCollider::CollideDirection(const Collider* other) const
{
    return -other->CollideDirection(this);
}

sf::Vector2f BoxCollider::CollideDirection(const BoxCollider* other) const
{
    if (position.x + size.x <= other->position.x + other->size.x / 2)
        if (position.x < (position.y - other->position.y) * size.x / size.y + other->position.x &&
            position.x < (other->position.y + other->size.y - position.y) * size.x / size.y + other->position.x)
            return { -1,0 };
    if (position.x >= other->position.x + other->size.x / 2)
        if (position.x + size.x > (position.y - other->position.y) * size.x / size.y + other->position.x &&
            position.x + size.x > (other->position.y + other->size.y - position.y) * size.x / size.y + other->position.x)
			return { 1,0 };
    if (position.y + size.y <= other->position.y + other->size.y / 2)
        if (position.y < (position.x - other->position.x) * size.y / size.x + other->position.y &&
            position.y < (other->position.x + other->size.x - position.x) * size.y / size.x + other->position.y)
            return { 0,-1 };
    if (position.y >= other->position.y + other->size.y / 2)
        if (position.y + size.y > (position.x - other->position.x) * size.y / size.x + other->position.y &&
			position.y + size.y > (other->position.x + other->size.x - position.x) * size.y / size.x + other->position.y)
            return { 0,1 };
    return {0, 1};
	// (position.y - other->position.y) * size.x / size.y + other->position.x > position.x
}

sf::Vector2f BoxCollider::CollideDirection(const CircleCollider* other) const
{
    sf::Vector2f center = other->center;
    if (center.x >= position.x && center.x <= position.x + size.x)
    {
        if (center.y >= position.y + size.y / 2) return { 0, -1 };
        else return { 0, 1 };
    }
    if (center.y >= position.y && center.y <= position.y + size.y)
    {
        if (center.x >= position.x + size.x / 2) return { -1, 0 };
		else return { 1, 0 };
    }
	sf::Vector2f nearestCorner;
    if (center.x < position.x + size.x / 2)
    {
        nearestCorner.x = position.x;
    }
    else
    {
        nearestCorner.x = position.x + size.x;
	}
    if (center.y < position.y + size.y / 2)
    {
        nearestCorner.y = position.y;
    }
    else
    {
        nearestCorner.y = position.y + size.y;
    }
	return Normalize(nearestCorner - center);
}