#include "GameManager.h"

GameManager::GameManager(Racket* racket, LifeUI* lifeUI, Text* scoreText, Text* levelText, int currentLives)
{
	this->targetCount = 0;
	this->currentLives = currentLives;
	this->score = 0;
	this->racket = racket;
	this->lifeUI = lifeUI;
	this->scoreText = scoreText;
	this->levelText = levelText;
}

void GameManager::UpdateLogic()
{

}
