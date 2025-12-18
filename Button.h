#pragma once
#include "UI.h"
#include "SFML/System.hpp"
class UI;

class Button :
    public UI
{
public:
    static int id;
    int thisid;
    Button(sf::Vector2u pos, sf::Vector2u siz);
    void OnClick();
    void Render();
};

