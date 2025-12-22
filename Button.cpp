#include "Button.h"
#include "Engine.h"
#include "BoxCollider.h"
#include <iostream>

Button::Button(sf::Vector2u pos, sf::Vector2u siz, int _layer, std::function<void()> onClick)
{
	layer = _layer;
	width = siz.x;
	height = siz.y;
	left = pos.x - siz.x / 2;
	right = left + siz.x;
	bottom = pos.y - siz.y / 2;
	top = bottom + siz.y;
	collider = new BoxCollider({ 1.f * left, 1.f * bottom }, {1.f * width, 1.f * height});
	OnClick = onClick;
}

void Button::Render() {
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(left, bottom));
	Engine::window->draw(shape);
}