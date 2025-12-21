#include "Racket.h"
#include "Input.h"
#include "BoxCollider.h"

Racket::Racket(sf::Vector2f pos, sf::Vector2f siz)
{
	this->collider = new BoxCollider(pos, siz);
	this->pos = pos;
	this->size = siz;
}