#pragma once
#include "GameObject.h"

class Racket :
    public GameObject
{
public:
    sf::Vector2f pos;
    sf::Vector2f size;

    Racket(sf::Vector2f pos, sf::Vector2f siz);
    void Render();
    void UpdateLogic();
};

