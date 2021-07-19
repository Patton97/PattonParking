#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"

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
        sf::Clock deltaClock;
        sf::Clock clock;
    private: 
        // methods
        void start();
        void initWindow();
        void updateFPS();

        // variables
        sf::RenderWindow* window;
        sf::VideoMode* videoMode;
        sf::Event ev;
        std::string windowTitle;
        sf::Uint32 windowStyle;
        //std::vector<GameObject*> gameObject = {};

        Player* player;

        sf::Text* fpsText = new sf::Text();
        sf::Font* fpsTextFont = new sf::Font();
        sf::Time previousTime = sf::Time();
        sf::Time currentTime = sf::Time();
};

