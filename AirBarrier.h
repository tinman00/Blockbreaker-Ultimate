#pragma once
#include "GameObject.h"
#include "Base.h"
class AirBarrier :
    public GameObject
{
public:
    bool isVisible;
    AirBarrier(sf::Vector2f pos, sf::Vector2f siz, bool isVisible = false);
    void Render();
};

