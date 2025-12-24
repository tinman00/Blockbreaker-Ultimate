#pragma once
#include "UI.h"
#include "Base.h"
#include "SFML/graphics.hpp"
class UI;

class Text :
    public UI
{
public:
    sf::String str;
    sf::Color color;
    sf::Font font;
    int characterSize;
    Text(sf::Vector2u pos, const char* s, sf::Color c, sf::String fontpath, int cs);
	void Render();
	void SetString(std::string str);
};

