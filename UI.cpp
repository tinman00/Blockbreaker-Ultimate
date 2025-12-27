#include "UI.h"

bool UI::Enclose(int x, int y)
{
	return left <= x && x <= right && bottom <= y && y <= top;
}

UI::UI(sf::Vector2u pos, sf::Vector2u siz, int _layer)
{
	layer = _layer;
	width = siz.x;
	height = siz.y;
	left = pos.x;
	right = pos.x + siz.x;
	bottom = pos.y + siz.y / 2;
	top = pos.y;
}