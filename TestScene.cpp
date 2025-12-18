#include "TestScene.h"
#include "Button.h"

TestScene::TestScene()
{
	objects.push_back(new Button({ 400, 250 }, { 300, 200 }));
	objects.push_back(new Button({ 800, 350 }, { 400, 200 }));
}
