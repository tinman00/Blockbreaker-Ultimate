#pragma once
#include "GameObject.h"
#include "Racket.h"
#include "Text.h"
#include "LifeUI.h"
#include <set>
class Ball;
class GameManager :
    public GameObject
{
public:
	Racket* racket;
    int targetCount;
	std::set<Ball*> balls;
	int currentLives;
	int score;
	Text* scoreText;
	Text* levelText;
	LifeUI* lifeUI;
	bool gameEnd;

	GameManager(Racket* racket, LifeUI* lifeUI, Text* scoreText,
		Text* levelText, int currentLives);
	void UpdateLogic() override;
	void GameFailed();
	void GameSucceeded();
	void AddScore(int delta);
};

