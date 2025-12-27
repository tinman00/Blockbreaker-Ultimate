#include "UI.h"

bool UI::Enclose(int x, int y)
{
	return left <= x && x <= right && top <= y && y <= bottom;
}

UI::UI(sf::Vector2f pos, sf::Vector2f siz, int _layer)
{
	this->position = sf::Vector2f(pos.x, pos.y);
	this->size = siz;
	layer = _layer;
	width = siz.x;
	height = siz.y;
	left = pos.x;
	right = pos.x + siz.x;
	bottom = pos.y + siz.y;
	top = pos.y;
}

void UI::UpdatePivot()
{
	sf::Vector2f siz = size;
	sf::Vector2f pos = position;
	width = siz.x;
	height = siz.y;
	left = pos.x;
	right = pos.x + siz.x;
	bottom = pos.y + siz.y;
	top = pos.y;
}
