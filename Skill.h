#pragma once
#include "UI.h"
class Skill :
    public UI
{
public:
	enum class Type
	{
		Split = 0
	};
	Type type;
	Skill(sf::Vector2f position, sf::Vector2f size, Type type);
	void UpdateLogic() override;
	void Render() override;
	void OnCollision(Collider* other) override;
};

