#include "Ball.h"
#include "Base.h"
#include "BasicColliders.h"

Ball::Ball(sf::Vector2f pos, float radius, sf::Vector2f boundX)
{
	this->SetCollider(new CircleCollider(pos, radius));
	this->position = pos;
	this->radius = radius;
	this->boundX = boundX;
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
