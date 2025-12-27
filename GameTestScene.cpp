#include "GameTestScene.h"
#include "BasicObjects.h"
#include "Base.h"
#include "BasicUI.h"
#include <cstdlib>

GameTestScene::GameTestScene()
{
	int mapWidth = 20;
	int mapHeight = 8;
	float levelWidth = BOUNDARY_THICKNESS * 2 + mapWidth * BLOCK_WIDTH;
	float levelHeight = BOUNDARY_THICKNESS * 2 + (mapHeight + 10 + mapWidth * 0.4f) * BLOCK_HEIGHT;
	windowHeight = levelHeight;
	windowWidth = levelWidth + LEVEL_INFO_WIDTH;
	sf::Vector2u windowSize(windowWidth, windowHeight);

	auto racket = CreateObject("Racket", new Racket({ levelWidth / 2 - RACKET_WIDTH / 2, windowHeight - RACKET_Y_POS_TO_BOTTOM - RACKET_HEIGHT / 2}, 
		{RACKET_WIDTH, RACKET_HEIGHT}, {BOUNDARY_THICKNESS, levelWidth - BOUNDARY_THICKNESS},
		RACKET_SPEED
	));

	auto verticalBoundHeight = windowHeight + HIDE_FORBBIDEN_ZONE_HEIGHT;
	CreateObject("AirBarrier 1",
		new AirBarrier({ 0, 0 }, { BOUNDARY_THICKNESS, verticalBoundHeight }, true));
	CreateObject("AirBarrier 2",
		new AirBarrier({ levelWidth - BOUNDARY_THICKNESS, 0 }, { BOUNDARY_THICKNESS, verticalBoundHeight }, true));
	CreateObject("AirBarrier 3",
		new AirBarrier({ 0, 0 }, { levelWidth, BOUNDARY_THICKNESS }, true));
	CreateObject("Forbbiden Zone", 
		new ForbbidenZone({ 0, verticalBoundHeight }, { levelWidth, BOUNDARY_THICKNESS }));

	sf::Vector2u uiPositionInit(static_cast<unsigned>(levelWidth) + UI_OFFSET_X, 0);

	auto pauseButton = CreateObject("PauseButton",
		new Button(uiPositionInit + sf::Vector2u(0, UI_OFFSET_X), {static_cast<unsigned>(LEVEL_INFO_WIDTH - UI_OFFSET_X * 2), 100}, 1));
	auto scoreText = CreateObject("ScoreText",
		new Text(uiPositionInit + sf::Vector2u(0, static_cast<unsigned>(UI_OFFSET_X * 2 + 100)), "SCORE", sf::Color(191, 127, 0), "LLPixelFun.ttf", 60));
	auto levelText = CreateObject("LevelText",
		new Text(uiPositionInit + sf::Vector2u(0, levelHeight - 240), "LEVEL\n00000", sf::Color(211, 160, 0), "LLPixelFun.ttf", 60));
	auto lifeUI = CreateObject("LifeUI", new LifeUI());

	std::vector<Ball*> list;
	for (int i = 0; i < 4; i++) {
		auto ballGO = CreateObject(
			std::string("Ball ") + std::to_string(i),
			new Ball({ static_cast<float>(rand() % (static_cast<int>(levelWidth - 2 * BALL_RADIUS)) + BOUNDARY_THICKNESS + BALL_RADIUS),
				static_cast<float>(rand() % (static_cast<int>(mapHeight * BLOCK_HEIGHT)) + BOUNDARY_THICKNESS + BALL_RADIUS) },
				BALL_RADIUS, { BOUNDARY_THICKNESS, levelWidth - BOUNDARY_THICKNESS })
			);
		auto ball = dynamic_cast<Ball*>(ballGO);
		list.push_back(ball);
		ball->collider->velocity = { 0.6f * BALL_SPEED, 0.8f * BALL_SPEED };
	}
	// Create blocks
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight - 1; j++) {
			if (rand() % 2)
			{
				CreateObject(
					std::string("Block ") + std::to_string(i) + "-" + std::to_string(j),
					new FragileBlock(
						{ BOUNDARY_THICKNESS + i * BLOCK_WIDTH,
						BOUNDARY_THICKNESS + (j + 2) * BLOCK_HEIGHT },
						{ BLOCK_WIDTH,  BLOCK_HEIGHT })
				);
			}
			else
			{
				CreateObject(
					std::string("Block ") + std::to_string(i) + "-" + std::to_string(j),
					new HardBlock(
						{ BOUNDARY_THICKNESS + i * BLOCK_WIDTH,
						BOUNDARY_THICKNESS + (j + 2) * BLOCK_HEIGHT },
						{ BLOCK_WIDTH,  BLOCK_HEIGHT }, 3, sf::Color(191, 191, 191))
				);
			}
		}
	}
	//CreateObject("AirBarrier 5", new AirBarrier({ 450, 450 }, { 100, 100 }, true));
	//auto ball1 = GetObject<Ball>("Ball 1");
	//ball1->collider->velocity = { 100, 50 };
	//auto ball2 = GetObject<Ball>("Ball 2");
	//ball2->collider->velocity = { 30, -50 };
	CreateObject("FrameRateText", new RunningStatsText({ 24, 24 }, sf::Color::Green, "Deng.ttf", 24));
}
