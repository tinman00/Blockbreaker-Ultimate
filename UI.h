#pragma once
#include "GameObject.h"
#include "SFML/System.hpp"
#include <functional>

class UI :
    public GameObject
{
public:
    sf::Vector2f size;
    int layer; // Greater layer means ui upper.
    int top, bottom;
    int left, right;
    int width, height;
    std::function<void()> OnClick = []() {};
    bool Enclose(int x, int y);
    UI(sf::Vector2f pos, sf::Vector2f siz, int _layer);
    UI() = default;
    void UpdatePivot();
};

