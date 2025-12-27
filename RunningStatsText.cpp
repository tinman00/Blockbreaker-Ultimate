#include "RunningStatsText.h"

RunningStatsText::RunningStatsText(sf::Vector2u pos, sf::Color c, sf::String fontpath, int cs, int layer) :
	Text(pos, "", c, fontpath, cs, layer)
{
	
}

void RunningStatsText::Start() {
	clock = sf::Clock();
}

void RunningStatsText::UpdateLogic() {
	auto currentTime = clock.getElapsedTime().asMilliseconds();
	logicTimeSequence.push_back(currentTime);
	while (!logicTimeSequence.empty() && currentTime - logicTimeSequence.front() > 1000) {
		logicTimeSequence.pop_front();
	}
	if (currentTime - lastUpdateTime > 200) {
		logicFPS = "logicFPS: " + std::to_string(logicTimeSequence.size()) + "\n";
		lastUpdateTime = currentTime;
	}
}

void RunningStatsText::Render()
{
	auto currentTime = clock.getElapsedTime().asMilliseconds();
	renderTimeSequence.push_back(currentTime);
	while (!renderTimeSequence.empty() && currentTime - renderTimeSequence.front() > 1000) {
		renderTimeSequence.pop_front();
	}
	if (currentTime - lastRenderTime > 200) {
		renderFPS = "renderFPS: " + std::to_string(renderTimeSequence.size() / 2) + "\n";
		lastRenderTime = currentTime;
	}
	this->SetString(logicFPS + renderFPS);
	Text::Render();
}
