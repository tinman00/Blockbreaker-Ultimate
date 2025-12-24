#include "Collider.h"
#include "Settings.h"
#include <iostream>

bool Collider::IsCollideWith(const Collider* other) const
{
    return false;
}

bool Collider::IsCollideWith(const BoxCollider* other) const
{
    return false;
}

bool Collider::IsCollideWith(const CircleCollider* other) const
{
    return false;
}

sf::Vector2f Collider::CollideDirection(const Collider* other) const
{
    return { 0, 0 };
}

sf::Vector2f Collider::CollideDirection(const BoxCollider* other) const
{
    return { 0, 0 };
}
sf::Vector2f Collider::CollideDirection(const CircleCollider* other) const
{
    return { 0, 0 };
}

void Collider::MoveBabyStep()
{
    if (!isFixed)
    {
        position += (1.f / FRAMES_PER_SEC) * velocity;
    }
}

void Collider::MoveFullStep()
{
	if (!isFixed)
        position += velocity;
}

void Collider::CollideWith(Collider* other)
{
    if (!isFixed && IsCollideWith(other))
    {
        //std::cout << "Collision: \"" << this->owner->name << "\""
            //<< " with \"" << other->owner->name << "\"" << std::endl;
        sf::Vector2f dir = CollideDirection(other);
		float dot = velocity.x * dir.x + velocity.y * dir.y;
        if(dot < 0)
        {
            velocity -= 2.f * dir * dot;
		}
    }
}