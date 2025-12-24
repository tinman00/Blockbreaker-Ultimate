#include "RunningStatsText.h"

RunningStatsText::RunningStatsText(sf::Vector2u pos, sf::Color c, sf::String fontpath, int cs) :
	Text(pos, "", c, fontpath, cs)
{
	
}

void RunningStatsText::Start() {
	clock = sf::Clock();
}

void RunningStatsText::UpdateLogic() {
	auto currentTime = clock.getElapsedTime().asMilliseconds();
	timeSequence.push_back(currentTime);
	while (!timeSequence.empty() && currentTime - timeSequence.front() > 1000) {
		timeSequence.pop_front();
	}
	if (currentTime - lastUpdateTime > 200) {
		this->SetString("FPS: " + std::to_string(timeSequence.size()));
		lastUpdateTime = currentTime;
	}
}