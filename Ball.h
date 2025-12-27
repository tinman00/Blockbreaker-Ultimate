#pragma once
#include "GameObject.h"
#include "GameManager.h"
#include "Base.h"

class Ball :
    public GameObject
{
public:
    static int id;
    float radius;
    sf::Vector2f boundX;
    bool isReleased;
    GameManager* gameManager;

    Ball(sf::Vector2f pos, float radius, sf::Vector2f boundX);
    void Start() override;
    void Render();
	void UpdateLogic() override;
    void OnDestroy() override;
};

