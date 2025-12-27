#pragma once
#include "GameObject.h"
#include "Racket.h"
#include "Text.h"
#include "LifeUI.h"
class GameManager :
    public GameObject
{
public:
	Racket* racket;
    int targetCount;
	int ballCount;
	int currentLives;
	int score;
	Text* scoreText;
	Text* levelText;
	LifeUI* lifeUI;
	GameManager(Racket* racket, LifeUI* lifeUI, Text* scoreText,
		Text* levelText, int currentLives);
	void UpdateLogic() override;
};

