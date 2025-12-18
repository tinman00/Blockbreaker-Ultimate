#include "SFML/Graphics.hpp"
#include <iostream>
#include "Engine.h"

int main()
{
    std::cout << "Hello worrld!!!" << std::endl;
    Engine::Initialize();
    Engine::Run();
    return 0;
}