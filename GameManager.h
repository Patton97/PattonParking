#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "GameObject.h"

class GameManager
{
    public:
        // construction
        GameManager();
        virtual ~GameManager();

        // accessors
        const bool isWindowOpen() const;

        // methods
        void eventUpdate();
        void update();
        void render();

        // variables
        sf::Clock clock;
        sf::Clock deltaClock;
    private:
        // methods
        void start();
        void initWindow();
        void updateDeltaTime();

        // variables
        sf::RenderWindow* window = nullptr;
        sf::VideoMode* videoMode = nullptr;
        sf::Event ev = sf::Event();
        std::string windowTitle = std::string();
        sf::Uint32 windowStyle = 0;
        std::vector<GameObject*> gameObjects = {};
        
        sf::Time previousTime = sf::Time();
        sf::Time currentTime = sf::Time();
        sf::Time deltaTime = sf::Time::Zero;
public:
    GameManager(GameManager const&) = delete;
    void operator=(GameManager const&) = delete;
};

