#pragma once
#include "Block.h"
class HardBlock :
    public Block
{
public:
	int hitPoints = 1;
	int32_t lastHitTime;
    HardBlock(sf::Vector2f pos, sf::Vector2f siz,int hp, sf::Color color = sf::Color::White);
	void Start() override;
	void OnCollision(Collider* other) override;
	void Render() override;
};

