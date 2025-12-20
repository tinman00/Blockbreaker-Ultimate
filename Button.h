#pragma once
#include "UI.h"
#include "SFML/System.hpp"
class UI;

class Button :
    public UI
{
public:
    Button(sf::Vector2f pos, sf::Vector2f siz);
    void OnClick();
    void Render();
}; 

