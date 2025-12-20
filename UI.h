#pragma once
#include "GameObject.h"
#include "SFML/System.hpp"
#include <functional>

class UI :
    public GameObject
{
public:
    int layer; // Greater layer means ui upper.
    int top, bottom;
    int left, right;
    int width, height;
    std::function<void()> OnClick = []() {};
    bool Enclose(int x, int y);
    UI(sf::Vector2u pos, sf::Vector2u siz, int _layer);
    UI() = default;
};

