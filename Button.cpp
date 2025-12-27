#include "Button.h"
#include "Engine.h"
#include "BoxCollider.h"
#include <iostream>

Button::Button(sf::Vector2f pos, sf::Vector2f siz, int _layer, std::function<void()> onClick)
	: UI(pos, siz, _layer)
{
	// collider = new BoxCollider({ 1.f * left, 1.f * bottom }, {1.f * width, 1.f * height});
	OnClick = onClick;
}

void Button::Render() {
	sf::RectangleShape shape(size);
	shape.setPosition(position);
	Engine::window->draw(shape);
}