#include "FragileBlock.h"
#include "Base.h"
#include "BasicObjects.h"

FragileBlock::FragileBlock(sf::Vector2f pos, sf::Vector2f siz, sf::Color color) :
	Block(pos, siz, color)
{

}

void FragileBlock::OnCollision(Collider* other)
{
	if (dynamic_cast<Ball*>(other->owner)) 
	{
		//std::cout << "FragileBlock collided with Ball, destroying self." << std::endl;
		Engine::Destroy(this);
	}
}

void FragileBlock::Start()
{
	auto gameManager = Engine::GetObject<GameManager>("GameManager");
	gameManager->targetCount++;
}

void FragileBlock::OnDestroy()
{
	auto gameManager = Engine::GetObject<GameManager>("GameManager");
	gameManager->targetCount--;
	gameManager->AddScore(FRAGILE_BLOCK_SCORE);
}