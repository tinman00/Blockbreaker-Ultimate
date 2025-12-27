#include "Ball.h"
#include "Base.h"
#include "Engine.h"
#include "BasicObjects.h"
#include "BasicColliders.h"
#include <cstdlib>


Ball::Ball(sf::Vector2f pos, float radius, sf::Vector2f boundX)
{
	this->SetCollider(new CircleCollider(pos, radius));
	this->collider->velocity = sf::Vector2f(0, 0);
	this->collider->isFixed = true;
	this->position = pos;
	this->radius = radius;
	this->boundX = boundX;
	this->isReleased = false;
	this->gameManager = nullptr;
}

void Ball::Start()
{
	gameManager = Engine::GetObject<GameManager>("GameManager");
	gameManager->balls.insert(this);
}

void Ball::Render() {
	sf::CircleShape shape(radius);
	shape.setPosition({ position.x - radius , position.y - radius});
	Engine::window->draw(shape);
	//auto coll = dynamic_cast<CircleCollider*>(this->collider);
	//std::cout << "Ball_Coll position: (" << coll->position.x << ", " << coll->position.y << ")" << std::endl;
	//std::cout << "Ball_Coll radius: " << coll->radius << std::endl;
}

void Ball::UpdateLogic()
{
	if (!isReleased) {
		this->collider->position = gameManager->racket->collider->position + sf::Vector2f(RACKET_WIDTH / 2, -BALL_HANG_HEIGHT);
	}
	if (!isReleased && Input::GetKeydown(Input::Binds::Fire)) {
		this->isReleased = true;

		float offset = static_cast<float>(rand() % 20000 - 10000) / 10000.f;
		float angle = offset * 60.f;
		float arc = angle / 180.f * std::acos(-1);
		this->collider->velocity = sf::Vector2f(BALL_SPEED * std::sin(arc), -BALL_SPEED * std::cos(arc));
		this->collider->isFixed = false;
	}

	if (position.x - radius < boundX.x) {
		position.x = boundX.x + radius;
		collider->position.x = boundX.x + radius;
		if (collider->velocity.x < 0)
			collider->velocity.x = -collider->velocity.x;
	}
	if (position.x + radius > boundX.y) {
		position.x = boundX.y - radius;
		collider->position.x = boundX.y - radius;
		if (collider->velocity.x > 0)
			collider->velocity.x = -collider->velocity.x;
	}
}

void Ball::OnDestroy()
{
	gameManager->balls.erase(this);
}
