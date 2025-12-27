#pragma once
#include "UI.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
class LifeUI :
    public UI
{
public:
    int currentLives;
    int characterSize;
    sf::Font font;
    sf::Color color;
    LifeUI(sf::Vector2f pos, int currentLives, sf::Color c,
        sf::String fontPath, int cs, int layer);
    void UpdateCurrentLives(int currentLives);
    void Render() override;
};

