#pragma once
#include "Text.h"
#include "Base.h"
#include <deque>

class RunningStatsText :
    public Text
{
public:
	sf::Clock clock;
    std::deque<float> logicTimeSequence;
    std::deque<float> renderTimeSequence;
    std::int32_t lastUpdateTime = 0;
    std::int32_t lastRenderTime = 0;
    std::string logicFPS, renderFPS;

    RunningStatsText(sf::Vector2f pos, sf::Color c, sf::String fontpath, int cs, int layer);
    void Start() override;
    void UpdateLogic() override;
    void Render() override;
};

