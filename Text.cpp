#include "Text.h"
#include "Engine.h"

Text::Text(sf::Vector2u pos, sf::String s, sf::Color c, sf::String fontpath, int cs)
{
	sf::Vector2u siz = sf::Vector2u(s.getSize() * cs, cs);
	thisid = ++id;
	width = siz.x;
	height = siz.y;
	left = pos.x - siz.x / 2;
	right = left + siz.x;
	bottom = pos.y - siz.y / 2;
	top = bottom + siz.y;
	str = s;
	color = c;
	characterSize = cs;
	if (!font.openFromFile(std::filesystem::path(fontpath))) {
		return;
	}
}

void Text::Render() {
	sf::Text text(font, str, characterSize);
	text.setFillColor(color);
	text.setPosition(sf::Vector2f(left, top));
	Engine::window->draw(text);
}
