#include "GameTestScene.h"
#include "BasicObjects.h"
#include "Base.h"
#include "BasicUI.h"
#include <cstdlib>

GameTestScene::GameTestScene()
{
	srand(0);
	int mapWidth = 20;
	int mapHeight = 20;
	int currentLives = 3;
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

	sf::Vector2f uiPositionInit(static_cast<unsigned>(levelWidth) + UI_OFFSET_X, 0);

	sf::Color uiColor = sf::Color(251, 124, 34);
	auto pauseButton = dynamic_cast<TextedButton*>(CreateObject("PauseButton",
		new TextedButton(uiPositionInit + sf::Vector2f(0, UI_OFFSET_X),
			{ static_cast<unsigned>(LEVEL_INFO_WIDTH - UI_OFFSET_X * 2), 100 }, 5,
			[]() {
				std::cout << "Pause button clicked." << std::endl;
				Engine::GetObject<PausePanel>("PausePanel")->ToggleVisibility();
				Engine::TogglePause();
			})));
	pauseButton->SetText("PAUSE", sf::Color::Black, "LLPixelFun.ttf", 42);
	auto pausePanel = dynamic_cast<PausePanel*>(CreateObject("PausePanel",
		new PausePanel({0, 0}, {levelWidth, levelWidth}, 3)));
	pausePanel->isActive = false;

	auto scoreText = CreateObject("ScoreText",
		new Text(uiPositionInit + sf::Vector2f(0, static_cast<unsigned>(UI_OFFSET_X * 2 + 100)),
			"SCORE", uiColor, "LLPixelFun.ttf", 64, 1));
	auto levelText = CreateObject("LevelText",
		new Text(uiPositionInit + sf::Vector2f(0, levelHeight - 240),
			"LEVEL\n00000", uiColor, "LLPixelFun.ttf", 64, 1));
	auto lifeUI = CreateObject("LifeUI",
		new LifeUI(uiPositionInit + sf::Vector2f(0, levelHeight / 2 - 80),
			currentLives, uiColor, "LLPixelFun.ttf", 64, 1));

	auto gameManager = CreateObject("GameManager",
		new GameManager(dynamic_cast<Racket*>(racket), dynamic_cast<LifeUI*>(lifeUI),
			dynamic_cast<Text*>(scoreText), dynamic_cast<Text*>(levelText), currentLives));

	std::vector<Ball*> list;
	for (int i = 0; i < 4; i++) {
		auto ballGO = CreateObject(
			std::string("Ball-") + std::to_string(i),
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
			if (i == mapWidth / 2 || i == mapWidth / 2 - 1) continue;
			if (rand() % 10 < 5)
			{
				if (rand() % 10 < 5)
				{
					CreateObject(
						std::string("Block ") + std::to_string(i) + "-" + std::to_string(j),
						new FragileBlock(
							{ BOUNDARY_THICKNESS + i * BLOCK_WIDTH,
							BOUNDARY_THICKNESS + (j + 2) * BLOCK_HEIGHT },
							{ BLOCK_WIDTH,  BLOCK_HEIGHT })
					);
				}
			}
			else
			{
				if (rand() % 10 < 5)
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
	}
	for (int i = 0; i < mapWidth; i++) {
		if (i == mapWidth / 2 || i == mapWidth / 2 - 1) continue;
		CreateObject(
			std::string("Block ") + std::to_string(i) + "-" + std::to_string(mapHeight - 1),
			new UnbreakableBlock(
				{ BOUNDARY_THICKNESS + i * BLOCK_WIDTH,
				BOUNDARY_THICKNESS + (mapHeight + 1) * BLOCK_HEIGHT },
				{ BLOCK_WIDTH,  BLOCK_HEIGHT }, sf::Color(95, 95, 95))
		);
	}
	//CreateObject("AirBarrier 5", new AirBarrier({ 450, 450 }, { 100, 100 }, true));
	//auto ball1 = GetObject<Ball>("Ball 1");
	//ball1->collider->velocity = { 100, 50 };
	//auto ball2 = GetObject<Ball>("Ball 2");
	//ball2->collider->velocity = { 30, -50 };
	CreateObject("FrameRateText", new RunningStatsText({ 24, 24 }, sf::Color::Green, "Deng.ttf", 24, 1));
}
