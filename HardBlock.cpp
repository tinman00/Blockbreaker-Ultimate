#include "HardBlock.h"
#include "Base.h"
#include "BasicObjects.h"
#include <cstdlib>

HardBlock::HardBlock(sf::Vector2f pos, sf::Vector2f siz, int hp, sf::Color color)
	: Block(pos, siz, color)
{
	this->hitPoints = hp;
}

void HardBlock::Start()
{
	lastHitTime = Engine::GetTimeMillis() - 999999;
	auto gameManager = Engine::GetObject<GameManager>("GameManager");
	gameManager->targetCount++;
}

void HardBlock::OnCollision(Collider* other)
{
	if (dynamic_cast<Ball*>(other->owner)) {
		hitPoints--;
		if (hitPoints <= 0) {
			Engine::Destroy(this);
		}
		auto currentTime = Engine::GetTimeMillis();
		lastHitTime = currentTime;
	}
}

void HardBlock::Render() {
	sf::RectangleShape shadowShape(sf::Vector2f(size.x, size.y));
	shadowShape.setPosition(sf::Vector2f(position.x, position.y));
	shadowShape.setFillColor(sf::Color::Black);
	Engine::window->draw(shadowShape);
	sf::RectangleShape colorShape(sf::Vector2f(size.x - 4.f, size.y - 4.f));
	colorShape.setPosition(sf::Vector2f(position.x, position.y));
	colorShape.setFillColor(color);
	Engine::window->draw(colorShape);

	sf::RectangleShape layeredShadowShape(sf::Vector2f(size.x - 6.f, size.y - 6.f));
	layeredShadowShape.setPosition(sf::Vector2f(position.x + 6.f, position.y + 6.f));
	layeredShadowShape.setFillColor(sf::Color::Black);
	Engine::window->draw(layeredShadowShape);
	sf::RectangleShape layeredcolorShape(sf::Vector2f(size.x - 10.f, size.y - 10.f));
	layeredcolorShape.setPosition(sf::Vector2f(position.x, position.y));
	layeredcolorShape.setFillColor(color);
	Engine::window->draw(layeredcolorShape);

	auto currentTime = Engine::GetTimeMillis();
	if (currentTime - lastHitTime < 200) {
		if (currentTime - lastHitTime < 60) {
			float dx = (currentTime - lastHitTime) / 60.f;
			sf::RectangleShape flashShape1(sf::Vector2f(6.f, (size.y - 4.f) * dx));
			flashShape1.setPosition(sf::Vector2f(position.x + size.x - 10.f, position.y + size.y - 10.f - (size.y - 4.f) * dx));
			flashShape1.setFillColor(sf::Color::White);
			Engine::window->draw(flashShape1);
			sf::RectangleShape flashShape2(sf::Vector2f((size.x - 4.f) * dx, 6.f));
			flashShape2.setPosition(sf::Vector2f(position.x + size.x - 10.f - (size.x - 4.f) * dx, position.y + size.y - 10.f));
			flashShape2.setFillColor(sf::Color::White);
			Engine::window->draw(flashShape2);
		}
		else if (currentTime - lastHitTime < 120) {
			sf::RectangleShape flashShape(sf::Vector2f(size.x - 4.f, size.y - 4.f));
			flashShape.setPosition(sf::Vector2f(position.x, position.y));
			flashShape.setFillColor(sf::Color::White);
			Engine::window->draw(flashShape);
		}
		else {
			float dx = (currentTime - lastHitTime - 120) / 80.f;
			sf::RectangleShape flashShape1(sf::Vector2f(6.f, (size.y - 4.f) * (1 - dx)));
			flashShape1.setPosition(sf::Vector2f(position.x, position.y));
			flashShape1.setFillColor(sf::Color::White);
			Engine::window->draw(flashShape1);
			sf::RectangleShape flashShape2(sf::Vector2f((size.x - 4.f) * (1 - dx), 6.f));
			flashShape2.setPosition(sf::Vector2f(position.x, position.y));
			flashShape2.setFillColor(sf::Color::White);
			Engine::window->draw(flashShape2);
		}
	}
}

void HardBlock::OnDestroy()
{
	auto gameManager = Engine::GetObject<GameManager>("GameManager");
	gameManager->targetCount--;

	if (rand() % 100 < SKILL_DROP_CHANCE_PERCENT) {
		Skill::Type type = Skill::Type::Split;
		auto skill = new Skill(
			position + size / 2.f - sf::Vector2f(SKILL_SIZE / 2.f, SKILL_SIZE / 2.f),
			sf::Vector2f(SKILL_SIZE, SKILL_SIZE),
			type);
		Engine::CreateObject("Skill " + std::to_string(Engine::GetNextObjectID()), skill);
	}

	gameManager->AddScore(HARD_BLOCK_SCORE);
}
