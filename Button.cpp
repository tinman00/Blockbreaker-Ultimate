#include "Button.h"
#include "Engine.h"
#include <iostream>

int Button::id = 0;

Button::Button(sf::Vector2u pos, sf::Vector2u siz)
{
	thisid = ++id;
	layer = 1;
	width = siz.x;
	height = siz.y;
	left = pos.x - siz.x / 2;
	right = left + siz.x;
	bottom = pos.y - siz.y / 2;
	top = bottom + siz.y;
}

void Button::OnClick() {
	std::cout << "Click id: " << thisid << std::endl;
}

void Button::Render() {
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(left, bottom));
	Engine::window->draw(shape);
}