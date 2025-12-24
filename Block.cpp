#include "Block.h"
#include "BasicColliders.h"

Block::Block(sf::Vector2f pos, sf::Vector2f siz, sf::Color color)
{
	this->SetCollider(new BoxCollider(pos, siz));
	this->collider->isFixed = true;
	this->position = pos;
	this->size = siz;
	this->color = color;
}

void Block::Render()
{
	sf::RectangleShape shadowShape(sf::Vector2f(size.x, size.y));
	shadowShape.setPosition(sf::Vector2f(position.x, position.y));
	shadowShape.setFillColor(sf::Color::Black);
	Engine::window->draw(shadowShape);
	sf::RectangleShape colorShape(sf::Vector2f(size.x - 4.f, size.y - 4.f));
	colorShape.setPosition(sf::Vector2f(position.x, position.y));
	colorShape.setFillColor(color);
	Engine::window->draw(colorShape);
}