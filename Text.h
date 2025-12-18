#pragma once
#include "UI.h"
#include "SFML/System.hpp"
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
    Text(sf::Vector2u pos, sf::String s, sf::Color c, sf::String fontpath, int cs);
	void Render();
};

