#include "LifeUI.h"
#include "Base.h"

LifeUI::LifeUI(sf::Vector2f pos, int currentLives, sf::Color c,
	sf::String fontPath, int cs, int layer)
	: UI(pos, {0, 0}, layer),
	  currentLives(currentLives),
	  characterSize(cs),
	  color(c)
{
	if (!font.openFromFile(std::filesystem::path(fontPath))) {
		return;
	}

	sf::Text text(font, sf::String("LIFE:"), characterSize);
	sf::FloatRect bounds = text.getLocalBounds();
	this->size = bounds.size + sf::Vector2f(0, ((currentLives - 1) / 3 + 1) * 5 * BALL_RADIUS);
}

void LifeUI::UpdateCurrentLives(int currentLives)
{
	this->currentLives = std::max(0, currentLives);
	std::cout << "Current lives: " << currentLives << std::endl;
}

void LifeUI::Render()
{
	sf::Text text(font, sf::String("LIFE:"), characterSize);
	text.setFillColor(color);
	sf::FloatRect bounds = text.getLocalBounds();
	text.setPosition(position - bounds.position);
	Engine::window->draw(text);

	for (int i = 0; i < (currentLives - 1) / 3 + 1; i++) {
		for (int j = 0; j < std::min(currentLives - i * 3, 3); j++) {
			sf::CircleShape shape(BALL_RADIUS);
			shape.setPosition({ left + (5 * j + 1) * BALL_RADIUS, top + bounds.size.y + (5 * i + 2) * BALL_RADIUS });
			Engine::window->draw(shape);
		}
	}
}
