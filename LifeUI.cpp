#include "LifeUI.h"
#include "Base.h"

LifeUI::LifeUI(sf::Vector2u pos, int currentLives, sf::Color c,
	sf::String fontPath, int cs, int layer)
	: UI(pos, { static_cast<unsigned>(5 * cs), static_cast<unsigned>(cs +  2 * 4 * BALL_RADIUS)}, layer)
{
	this->currentLives = currentLives;
	this->characterSize = characterSize;
	if (!font.openFromFile(std::filesystem::path(fontPath))) {
		return;
	}
}

void LifeUI::UpdateCurrentLives(int currentLives)
{
}

void LifeUI::Render()
{
	sf::Text text(font, "LIFE:", characterSize);
	text.setFillColor(color);
	text.setPosition(sf::Vector2f(left, top));
	Engine::window->draw(text);

	for (int i = 0; i < currentLives / 3; i++) {
		for (int j = 0; j < std::min(currentLives - i * 3, 3); j++) {
			sf::CircleShape shape(BALL_RADIUS);
			shape.setPosition({ left + (4 * j + 1) * BALL_RADIUS, top + characterSize + (4 * i + 1) * BALL_RADIUS });
			Engine::window->draw(shape);
		}
	}
}
