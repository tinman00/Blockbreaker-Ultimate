#pragma once
#include "UI.h"
#include "SFML/System.hpp"
#include <functional>
class UI;

class Button :
    public UI
{
public:
    Button(sf::Vector2u pos, sf::Vector2u siz, int _layer, std::function<void()> onClick);
    void Render();
};

