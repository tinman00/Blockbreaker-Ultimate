#include "Button.h"
#include "Engine.h"
#include "BoxCollider.h"
#include <iostream>

int Button::id = 0;

Button::Button(sf::Vector2f pos, sf::Vector2f siz)
{
	thisid = ++id;
	layer = 1;
	width = siz.x;
	height = siz.y;
	left = pos.x - siz.x / 2;
	right = left + siz.x;
	bottom = pos.y - siz.y / 2;
	top = bottom + siz.y;
	collider = new BoxCollider({ 1.f * left, 1.f * bottom }, {1.f * width, 1.f * height});
	//这里pos是正中，但是boxcollider的pos我设的是left bottom
}

void Button::OnClick() {
	std::cout << "Click id: " << thisid << std::endl;
}

void Button::Render() {
	sf::RectangleShape shape(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(left, bottom));
	Engine::window->draw(shape);
}