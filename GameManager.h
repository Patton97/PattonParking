#pragma once

#include <iostream>

#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

#include "GameObject.h"

class GameManager
{
    public:
        friend int main();
        GameManager();
        virtual ~GameManager();

        const bool isWindowOpen() const;
    private:
        void initWindow();

        void start();
        void eventUpdate();
        void update();
        void render();
        
        void cycleRenderMode();

        sf::RenderWindow* window = nullptr;
        sf::VideoMode* videoMode = nullptr;
        sf::Event ev = sf::Event();
        std::string windowTitle = std::string();
        sf::Uint32 windowStyle = 0;
        std::vector<GameObject*> gameObjects = {};

        enum class RenderMode { All, GizmosOff, GizmosOnly };
        RenderMode m_renderMode = RenderMode::GizmosOff;
};

