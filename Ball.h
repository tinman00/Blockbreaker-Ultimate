#pragma once
#include "GameObject.h"
#include "Base.h"

class Ball :
    public GameObject
{
public:
    float radius;
    sf::Vector2f boundX;

    Ball(sf::Vector2f pos, float radius, sf::Vector2f boundX);
    void Render();
	void UpdateLogic() override;
};

