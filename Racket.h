#pragma once
#include "GameObject.h"
#include "SFML/System.hpp"

class Racket :
    public GameObject
{
public:
    float speed;
    sf::Vector2f bound;

    Racket(sf::Vector2f pos, sf::Vector2f siz, sf::Vector2f bound, float spd);
    void Render() override;
    void UpdateLogic() override;
	void OnCollision(Collider* other) override;
};

