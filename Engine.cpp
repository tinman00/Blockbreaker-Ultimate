#include "Engine.h"
#include "GameObject.h"
#include "Camera.h"
#include "Input.h"
#include "SFML/Graphics.hpp"
#include "UI.h"
#include "SceneManager.h"
#include <vector>
#include <iostream>

namespace Engine
{
    void Initialize()
    {
        SceneManager::LoadScene(dynamic_cast<Scene*>(new TestScene()));
        window = new sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Blockbreaker!");
        window->setFramerateLimit(120);
        Input::ResetKeyMap();
    }

    void Update()
    {
        UpdatePhysics();
        UpdateGameLogic();
        Render();
    }

    void UpdatePhysics()
    {
        for (auto obj : objects) {
            obj->UpdatePhysics();
        }
    }

    void UpdateGameLogic()
    {
        for (auto obj : objects) {
            obj->UpdateLogic();
        }
    }

    void Render()
    {
        for (auto obj : objects) {
            obj->Render();
        }
    }

    void Run()
    {
        while (window->isOpen())
        {
            window->clear();
            static bool isFocused = true;
            while (const std::optional<sf::Event> event = window->pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window->close();
                }
                if (event->is<sf::Event::FocusGained>())
                {
                    isFocused = true;
                }
                if (event->is<sf::Event::FocusLost>())
                {
                    isFocused = false;
                }
                if (const auto mouse = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    if (mouse->button == sf::Mouse::Button::Left) {
                        std::vector<UI*> uis;
                        int minLayer = INT32_MAX;
                        for (auto obj : objects)
                        {
                            UI* ui = dynamic_cast<UI*>(obj);
                            if (ui != nullptr && ui->Enclose(mouse->position.x, mouse->position.y))
                            {
                                uis.push_back(ui);
                                minLayer = ui->layer < minLayer ? ui->layer : minLayer;
                            }
                        }
                        for (auto ui : uis)
                        {
                            if (ui->layer == minLayer)
                            {
                                ui->OnClick();
                            }
                        }
                    }
                }
            }
            if (isFocused) Update();

            //std::cout << "Display." << std::endl;
            window->display();
        }
    }

    sf::RenderWindow* window;

    std::vector<GameObject*> objects;
    std::vector<Camera*> cameras;
}