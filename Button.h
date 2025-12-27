#pragma once
#include "UI.h"
#include "SFML/System.hpp"
#include <functional>
class UI;

class Button :
    public UI
{
public:
    Button(sf::Vector2f pos, sf::Vector2f siz, int _layer, std::function<void()> onClick = [](){});
    void Render() override;
};

