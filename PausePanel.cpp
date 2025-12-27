#include "PausePanel.h"
#include "Base.h"

PausePanel::PausePanel(sf::Vector2f pos, sf::Vector2f siz, int _layer)
	: UI(pos, siz, _layer)
{
	this->isVisible = false;
}

void PausePanel::Render()
{
	sf::RectangleShape shape(sf::Vector2f(size.x, size.y));
	shape.setFillColor(sf::Color(0, 0, 0, 150));
	shape.setPosition(sf::Vector2f(position.x, position.y));
	Engine::window->draw(shape);
	float barWidth = PAUSE_ICON_SIZE / 4;
	sf::RectangleShape leftBar(sf::Vector2f(barWidth, barWidth * 4));
	leftBar.setFillColor(sf::Color(255, 255, 255, 200));
	leftBar.setPosition(sf::Vector2f(position.x + size.x / 2 - barWidth * 1.5f, position.y + size.y / 2 - barWidth * 2.f));
	Engine::window->draw(leftBar);
	sf::RectangleShape rightBar(sf::Vector2f(barWidth, barWidth * 4));
	rightBar.setFillColor(sf::Color(255, 255, 255, 200));
	rightBar.setPosition(sf::Vector2f(position.x + size.x / 2 + barWidth * 0.5f, position.y + size.y / 2 - barWidth * 2.f));
	Engine::window->draw(rightBar);
}

void PausePanel::ToggleVisibility()
{
	this->isVisible = !isVisible;
	this->isActive = isVisible;
}