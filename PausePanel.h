#pragma once
#include "UI.h"
class PausePanel :
    public UI
{
public:
	bool isVisible;
	PausePanel(sf::Vector2f pos, sf::Vector2f siz, int _layer);
	void Render() override;
	void ToggleVisibility();
};

