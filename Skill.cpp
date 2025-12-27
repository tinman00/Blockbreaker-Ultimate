#include "Skill.h"
#include "BasicColliders.h"
#include "BasicObjects.h"
#include "Base.h"

Skill::Skill(sf::Vector2f position, sf::Vector2f size, Type type)
{
	this->SetCollider(new BoxCollider(position, size));
	this->collider->isFixed = true;
	this->position = position;
	this->size = size;
	this->type = type;
}

void Skill::UpdateLogic()
{
	float speed = SKILL_FALLING_SPEED;
	collider->position -= Engine::fixedDeltaTime * sf::Vector2f(0, -speed);
}

void Skill::Render()
{
	sf::RectangleShape shape(sf::Vector2f(size.x, size.y));
	shape.setFillColor(sf::Color(90, 194, 240));
	shape.setPosition(sf::Vector2f(position.x, position.y));
	Engine::window->draw(shape);
	if (this->type == Type::Split) {
		auto len = size.x < size.y ? size.x : size.y;
		// TODO draw three circles positioned like a triangle
		sf::CircleShape circle(len / 6);
		circle.setFillColor(sf::Color(255, 255, 255));
		circle.setPosition(sf::Vector2f(position.x + size.x / 2 + len / 6 * 0.2f,
			position.y + size.y / 2 - len / 6 * 2.f));
		Engine::window->draw(circle);
		circle.setPosition(sf::Vector2f(position.x + size.x / 2 - len / 6 * 2.0f,
			position.y + size.y / 2 - len / 6 * 1.5f));
		Engine::window->draw(circle);
		circle.setPosition(sf::Vector2f(position.x + size.x / 2 - len / 6 * 0.3f,
			position.y + size.y / 2 + len / 6 * 0.f));
		Engine::window->draw(circle);
	}

}

void Skill::OnCollision(Collider* other)
{
	if (dynamic_cast<Racket*>(other->owner)) {
		if (type == Type::Split) {
			auto gameManager = Engine::GetObject<GameManager>("GameManager");
			std::vector<Ball*> originalBalls;
			for (auto origin : gameManager->balls) {
				if (origin->isReleased) {
					originalBalls.push_back(origin);
				}
			}
			for (auto origin : originalBalls) {
				if (gameManager->balls.size() >= MAX_BALL_COUNT) {
					break;
				}
				auto ball1 = new Ball(origin->position, BALL_RADIUS, gameManager->racket->bound);
				ball1->isReleased = true;
				ball1->collider->isFixed = false;
				float speed = std::sqrt(origin->collider->velocity.x * origin->collider->velocity.x +
					origin->collider->velocity.y * origin->collider->velocity.y);
				sf::Vector2f dir = origin->collider->velocity.normalized();
				sf::Angle angle = sf::degrees(60.f);
				ball1->collider->velocity = dir.rotatedBy(angle) * speed;
				Engine::CreateObject("Ball " + std::to_string(Engine::GetNextObjectID()), ball1);
				if (gameManager->balls.size() >= MAX_BALL_COUNT) {
					break;
				}
				auto ball2 = new Ball(origin->position, BALL_RADIUS, gameManager->racket->bound);
				ball2->isReleased = true;
				ball2->collider->isFixed = false;
				ball2->collider->velocity = dir.rotatedBy(-angle) * speed;
				Engine::CreateObject("Ball " + std::to_string(Engine::GetNextObjectID()), ball2);
			}
		}
		Engine::Destroy(this);
	}
}
