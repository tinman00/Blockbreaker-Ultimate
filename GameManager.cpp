#include "GameManager.h"
#include "BasicObjects.h"
#include "Base.h"

GameManager::GameManager(Racket* racket, LifeUI* lifeUI, Text* scoreText,
	Text* levelText, int currentLives)
{
	this->targetCount = 0;
	this->balls = std::set<Ball*>();
	this->currentLives = currentLives;
	this->score = 0;
	this->racket = racket;
	this->lifeUI = lifeUI;
	this->scoreText = scoreText;
	this->levelText = levelText;
	this->gameEnd = false;
}

void GameManager::UpdateLogic()
{
	if (!gameEnd && targetCount <= 0) {
		gameEnd = true;
		GameSucceeded();
	}
	if (!gameEnd && balls.size() <= 0) {
		currentLives--;
		lifeUI->UpdateCurrentLives(currentLives);
		if (currentLives <= 0) {
			gameEnd = true;
			GameFailed();
		}
		else {
			auto ball = new Ball(racket->collider->position + sf::Vector2f(RACKET_WIDTH / 2, -BALL_HANG_HEIGHT), BALL_RADIUS, racket->bound);
			Engine::CreateObject("Ball " + std::to_string(Engine::GetNextObjectID()), ball);
		}
	}
}

void GameManager::GameFailed()
{
	Engine::isPaused = true;
	std::cout << "Game Failed!" << std::endl;
}

void GameManager::GameSucceeded()
{
	Engine::isPaused = true;
	std::cout << "Game Succeeded!" << std::endl;
}

void GameManager::AddScore(int delta) {
	score += delta;
	// 5 digits score display e.g.:"SCORE\n00045" greater than 99999 will be displayed as "SCORE\n99999"
	char buffer[16];
	sprintf_s(buffer, "SCORE\n%05d", std::min(score, 99999));
	scoreText->SetString(std::string(buffer));
}

