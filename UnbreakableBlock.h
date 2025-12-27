#pragma once
#include "Block.h"
class UnbreakableBlock :
    public Block
{
public:
	int32_t lastHitTime;
	UnbreakableBlock(sf::Vector2f pos, sf::Vector2f siz, sf::Color color = sf::Color::White);
	void Start() override;
	void OnCollision(Collider* other) override;
	void Render() override;
};

