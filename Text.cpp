#include "Text.h"
#include "Engine.h"
#include <cstring>
#include <cstdio>

Text::Text(sf::Vector2u pos, const char* s, sf::Color c, sf::String fontpath, int cs, int layer)
	: UI(pos, { static_cast<unsigned>(str.getSize() * cs), static_cast<unsigned>(cs) }, layer)
{
	str = sf::String::fromUtf8(s, s + strlen(s));
	sf::Vector2u siz = sf::Vector2u(str.getSize() * cs, cs);

	color = c;
	characterSize = cs;
	if (!font.openFromFile(std::filesystem::path(fontpath))) {
		return;
	}
}

void Text::Render() {
	sf::Text text(font, str, characterSize);
	text.setFillColor(color);
	text.setPosition(sf::Vector2f(left, bottom));
	Engine::window->draw(text);
}

void Text::SetString(std::string str)
{
	this->str = sf::String::fromUtf8(str.c_str(), str.c_str() + str.length());
}
