#pragma once
#include <SFML/System/Vector2.hpp>

float Distance(sf::Vector2f a, sf::Vector2f b);

float DistanceSquared(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f Normalize(sf::Vector2f v);