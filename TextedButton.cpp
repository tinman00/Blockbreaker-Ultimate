#include "TextedButton.h"
#include "Base.h"
#include "BasicUI.h"

TextedButton::TextedButton(sf::Vector2f pos, sf::Vector2f siz, int _layer, std::function<void()> onClick)
	: Button(pos, siz, _layer, onClick)
{
	text = nullptr;
	textStr = nullptr;
	fontPath = sf::String();
	textColor = sf::Color();
	characterSize = 0;
}

void TextedButton::SetText(const char* s, sf::Color c, sf::String fontpath, int cs)
{
	if (text) {

	}
	else {
		this->textStr = s;
		this->textColor = c;
		this->fontPath = fontpath;
		this->characterSize = cs;
	}
}

void TextedButton::Start()
{
	text = dynamic_cast<Text*>(Engine::CreateObject(this->name + "_text",
		new Text(position + size * 0.5f,
			textStr, textColor, fontPath, characterSize, layer + 1), this));
	text->position = text->position - text->size * 0.5f;
	text->UpdatePivot();
}
