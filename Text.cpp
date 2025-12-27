#include "Text.h"
#include "Engine.h"
#include <cstring>
#include <cstdio>

Text::Text(sf::Vector2f pos, const char* s, sf::Color c, sf::String fontpath, int cs, int layer)
	: UI(pos, {0, 0}, layer)
{
	if (!font.openFromFile(std::filesystem::path(fontpath))) {
		return;
	}
	str = sf::String::fromUtf8(s, s + strlen(s));
	color = c;
	characterSize = cs;
	sf::Text text(font, str, characterSize);
	sf::FloatRect globalBounds = text.getGlobalBounds();
	size = globalBounds.size;
	UpdatePivot();
}

void Text::Render() {
	sf::Text text(font, str, characterSize);
	sf::FloatRect bounds = text.getLocalBounds();
	text.setPosition(position - bounds.position);
	text.setFillColor(color);
	Engine::window->draw(text);
}

void Text::SetString(std::string str)
{
	this->str = sf::String::fromUtf8(str.c_str(), str.c_str() + str.length());
}
