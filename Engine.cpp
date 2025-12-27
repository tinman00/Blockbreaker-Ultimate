#include "Engine.h"
#include "Base.h"
#include "GameObject.h"
#include "Camera.h"
#include "SFML/Graphics.hpp"
#include "UI.h"
#include "TestScene.h"
#include "Ball.h"
#include "GameTestScene.h"

namespace Engine
{
	std::vector<GameObject*> toDelete = {};
	sf::Clock gameClock;

    void resetViewport()
    {
        sf::View view = window->getView();
        view.setSize(static_cast<sf::Vector2f>(window->getSize()));
        view.setCenter(static_cast<sf::Vector2f>(window->getSize()) / 2.f);
		window->setView(view);
    }

    void Initialize()
    {
        window = new sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Blockbreaker!", sf::Style::Titlebar | sf::Style::Close);
        resetViewport();
        window->setFramerateLimit(FRAMES_PER_SEC);
        Input::ResetKeyMap();
        SceneManager::LoadScene(dynamic_cast<Scene*>(new GameTestScene()));
    }

    void Update()
    {
        UpdatePhysics();
        UpdateGameLogic();
        Render();
        ClearBin();
    }

    void UpdatePhysics()
    {
		for (auto& [key, obj] : objects) {
			if (!obj->GetActive()) continue;
            if (!obj->collider) continue;
			//obj->UpdatePhysics();
            //std::cout << "Object: \"" << obj->name << "\""
                //<< ".velocity: (" << obj->collider->velocity.x << ", " << obj->collider->velocity.y << ")" << std::endl;
            //std::cout << "Object: \"" << obj->name << "\""
                //<< ".isActive: " << (obj->isActive ? "True" : "False") << std::endl;
			obj->collider->MoveBabyStep();
		}
        for (auto& [key1, obj1] : objects) {
            if (!obj1->GetActive()) continue;
            if (!obj1->collider) continue;
            auto& coll1 = obj1->collider;
            if (coll1->isFixed) continue;
            for (auto& [key2, obj2] : objects) {
                if (!obj2->GetActive() || obj1 == obj2) continue;
                if (dynamic_cast<Ball*>(obj1) && dynamic_cast<Ball*> (obj2)) continue;
                if (!obj2->collider) continue;
                auto& coll2 = obj2->collider;
                coll1->CollideWith(coll2);
            }
        }
        for (auto& [key, obj] : objects) {
            if (!obj->collider) continue;
            obj->SyncPosition();
        }
    }

    void UpdateGameLogic()
    {
        for (auto& [key, obj] : objects) {
            if (!obj->GetActive()) continue;
            obj->UpdateLogic();
        }
        for (auto& [key1, obj1] : objects) {
            if (!obj1->GetActive()) continue;
            if (!obj1->collider) continue;
            auto& coll1 = obj1->collider;
            if (coll1->isFixed) continue;
            for (auto& [key2, obj2] : objects) {
                if (!obj2->GetActive() || obj1 == obj2) continue;
                if (!obj2->collider) continue;
                auto& coll2 = obj2->collider;
                if (coll1->IsCollideWith(coll2)) {
					obj1->OnCollision(coll2);
					if (coll2->isFixed) obj2->OnCollision(coll1);
                }
            }
        }
    }

    void Render()
    {
        for (auto &[key, obj] : objects) {
            if (!obj->GetActive()) continue;
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
                        int topLayer = INT32_MIN;
                        for (auto &[key, obj] : objects)
                        {
                            UI* ui = dynamic_cast<UI*>(obj);
                            if (ui && ui->GetActive() && ui->Enclose(mouse->position.x, mouse->position.y))
                            {
                                uis.push_back(ui);
                                topLayer = ui->layer > topLayer ? ui->layer : topLayer;
                            }
                        }
                        for (auto ui : uis)
                        {
                            if (ui->layer == topLayer)
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

    void Destroy(GameObject* obj)
    {
        obj->OnDestroy();
		toDelete.push_back(obj);
		obj->SetActive(false);
    }

    void Delete(GameObject* obj)
    {
        for (auto child : obj->children) {
            Destroy(child);
        }
        objects.erase(obj->name);
        delete obj;
    }

    void ClearBin()
    {
        for (auto obj : toDelete) {
            Delete(obj);
        }
		toDelete.clear();
	}

    int32_t GetTimeMillis()
    {
		return gameClock.getElapsedTime().asMilliseconds();
    }

    GameObject* CreateObject(std::string name, GameObject* obj, GameObject* father)
    {
        obj->name = name;
        obj->father = father;
        if (father) {
            father->children.push_back(obj);
        }
        if (objects.find(name) == objects.end()) {
            objects[name] = obj;
        }
        else {
            std::cerr << "Error: GameObject with name \"" << name << "\" has already been created" << std::endl;
            delete obj;
            obj = nullptr;
        }
        obj->Start();
        return obj;
    }

    sf::RenderWindow* window;

    std::unordered_map<std::string, GameObject*> objects;
    std::vector<Camera*> cameras;
}