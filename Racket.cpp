#include "Base.h"
#include "Racket.h"
#include "BoxCollider.h"
#include "Ball.h"

Racket::Racket(sf::Vector2f pos, sf::Vector2f siz, sf::Vector2f bound, float spd)
{
	this->SetCollider(new BoxCollider(pos, siz));
	this->position = pos;
	this->size = siz;
	this->speed = spd;
	this->bound = bound;
}

void Racket::Render() {
	sf::RectangleShape shape(sf::Vector2f(size.x, size.y));
	shape.setPosition(sf::Vector2f(position.x, position.y));
	Engine::window->draw(shape);
	//auto coll = dynamic_cast<BoxCollider*>(this->collider);
	//std::cout << "Racket_Coll position: (" << coll->position.x << ", " << coll->position.y << ")" << std::endl;
	//std::cout << "Racket_Coll size: (" << coll->size.x << ", " << coll->size.y << ")" << std::endl;
}

void Racket::UpdateLogic() {
	float vel = Input::GetHorizontal() * speed;
	collider->velocity = { vel, 0 };
	if (position.x < bound.x) {
		position.x = bound.x;
		collider->position.x = bound.x;
	}
	if (position.x + size.x > bound.y) {
		position.x = bound.y - size.x;
		collider->position.x = bound.y - size.x;
	}
}

void Racket::OnCollision(Collider* other)
{
	if (dynamic_cast<Ball*>(other->owner)) {
		auto ball = dynamic_cast<Ball*>(other->owner);
		float racketCenterX = position.x + size.x / 2;
		float ballCenterX = ball->position.x;
		float offset = (ballCenterX - racketCenterX) / (size.x / 2); // -1 to 1
		float angle = offset * 60.f; // Max 60 degrees angle
		float speed = std::sqrt(other->velocity.x * other->velocity.x + other->velocity.y * other->velocity.y);
		float rad = angle * 3.14159265f / 180.f;
		other->velocity.x = speed * std::sin(rad);
		other->velocity.y = -speed * std::cos(rad);
	}
}
