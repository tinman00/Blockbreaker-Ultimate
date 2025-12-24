#pragma once
#include "GameObject.h"
#include "Base.h"
class Block :
    public GameObject
{
public:
	sf::Color color;

    Block(sf::Vector2f pos, sf::Vector2f siz, sf::Color color = sf::Color::White);
	void Render() override;
};