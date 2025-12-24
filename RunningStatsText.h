#pragma once
#include "Text.h"
#include "Base.h"
#include <deque>

class RunningStatsText :
    public Text
{
public:
	sf::Clock clock;
    std::deque<float> timeSequence;
	std::int32_t lastUpdateTime = 0;

    RunningStatsText(sf::Vector2u pos, sf::Color c, sf::String fontpath, int cs);
    void Start();
    void UpdateLogic();
};

