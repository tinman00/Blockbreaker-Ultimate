#include "AirBarrier.h"
#include "BoxCollider.h"

AirBarrier::AirBarrier(sf::Vector2f pos, sf::Vector2f siz, bool isVisible)
{
	this->SetCollider(new BoxCollider(pos, siz));
	this->collider->isFixed = true;
	this->position = pos;
	this->size = siz;
	this->isVisible = isVisible;
}

void AirBarrier::Render() {
	if (!this->isVisible) return;
	sf::RectangleShape shape(sf::Vector2f(size.x, size.y));
	shape.setPosition(sf::Vector2f(position.x, position.y));
	Engine::window->draw(shape);
	//auto coll = dynamic_cast<BoxCollider*>(this->collider);
	//std::cout << "Barrier_Coll position: (" << coll->position.x << ", " << coll->position.y << ")" << std::endl;
	//std::cout << "Barrier_Coll size: (" << coll->size.x << ", " << coll->size.y << ")" << std::endl;
}
