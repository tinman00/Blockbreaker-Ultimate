#pragma once
#include "Block.h"
class FragileBlock :
    public Block
{
public:
	FragileBlock(sf::Vector2f pos, sf::Vector2f siz, sf::Color color = sf::Color::White);
	void OnCollision(Collider* other) override;
};

