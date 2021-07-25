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
    private:
        // methods
        void start();
        void initWindow();

        // variables
        sf::RenderWindow* window = nullptr;
        sf::VideoMode* videoMode = nullptr;
        sf::Event ev = sf::Event();
        std::string windowTitle = std::string();
        sf::Uint32 windowStyle = 0;
        std::vector<GameObject*> gameObjects = {};
};

