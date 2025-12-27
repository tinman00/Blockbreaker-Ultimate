#include "Collider.h"
#include "Base.h"
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

void Collider::MoveStep()
{
    if (!isFixed)
    {
        position += Engine::fixedDeltaTime * velocity;
    }
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