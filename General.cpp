#include"General.h"
#include <corecrt_math.h>

float Distance(sf::Vector2f a, sf::Vector2f b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

float DistanceSquared(sf::Vector2f a, sf::Vector2f b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

sf::Vector2f Normalize(sf::Vector2f v)
{
	float len = Distance({ 0, 0 }, v);
	if (len == 0) return { 0, 0 };
	return { v.x / len, v.y / len };
}