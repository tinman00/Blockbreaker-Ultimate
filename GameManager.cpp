#include "GameManager.h"
#include "BasicObjects.h"
#include "Base.h"

GameManager::GameManager(Racket* racket, LifeUI* lifeUI, Text* scoreText,
	Text* levelText, int currentLives)
{
	this->targetCount = 0;
	this->ballCount = 0;
	this->currentLives = currentLives;
	this->score = 0;
	this->racket = racket;
	this->lifeUI = lifeUI;
	this->scoreText = scoreText;
	this->levelText = levelText;
}

void GameManager::UpdateLogic()
{
	if (ballCount <= 0) {
		auto ball = new Ball(racket->collider->position + sf::Vector2f(RACKET_WIDTH / 2, -BALL_HANG_HEIGHT), BALL_RADIUS, racket->bound);
		Engine::CreateObject("Ball " + Ball::id, ball);
	}
}
