#include "UI.h"

void UI::OnClick()
{
}

bool UI::Enclose(int x, int y)
{
	return left <= x && x <= right && bottom <= y && y <= top;
}
