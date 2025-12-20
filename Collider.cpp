#include "Collider.h"

bool Collider::CollideWith(const Collider* other) const
{
    // 默认实现：基类不进行具体碰撞检测，返回 false
    return false;
}

bool Collider::CollideWith(const BoxCollider* other) const
{
    // 默认实现：由派生类覆盖
    return false;
}

bool Collider::CollideWith(const CircleCollider* other) const
{
    // 默认实现：由派生类覆盖
    return false;
}