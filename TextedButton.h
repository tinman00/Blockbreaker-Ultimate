#pragma once
#include "Button.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
class Text;
class TextedButton :
    public Button
{
public:
    Text* text;
    const char* textStr;
    sf::String fontPath;
    sf::Color textColor;
    int characterSize;

    TextedButton(sf::Vector2f pos, sf::Vector2f siz, int _layer, std::function<void()> onClick = []() {});
    void SetText(const char* s, sf::Color c, sf::String fontpath, int cs);
    void Start() override;
};

