#pragma once
#include <SFML\System\Clock.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "GameObject.h"

//// TODO: Now that we have gizmos, should this derive from a 'text' gizmo?

/// <summary>
/// This class stores logic refering to monitoring the FPS &amp; outputting this information to the screen (if requested)
/// </summary>
/// <remarks>This class is a singleton, the implemention used is derived from: https://stackoverflow.com/a/1008289/11649819 </remarks>
class FPSMonitor : public GameObject
{
    public:
#pragma region Static Methods
        static FPSMonitor& getInstance()
        {
            static FPSMonitor instance;
            return instance;
        }
#pragma endregion

#pragma region Member Methods
        void start() override;
        void update(sf::Time& deltaTime) override;
        void render(sf::RenderWindow& window) override;
#pragma endregion

    private:
#pragma region Constructors/Desconstructors
        FPSMonitor()
        {
            if (!this->fpsTextFont->loadFromFile(".\\assets\\fonts\\cour.ttf"))
            {
                std::cout << "Font failed to load" << std::endl;
            }
            this->fpsText->setFillColor(sf::Color::Red);
            this->fpsText->setFont(*fpsTextFont);
        }
#pragma endregion

#pragma region Member Variables
        sf::Text* fpsText = new sf::Text();
        sf::Font* fpsTextFont = new sf::Font();
#pragma endregion

    public:
        FPSMonitor(FPSMonitor const&) = delete; // required for singleton pattern
        void operator=(FPSMonitor const&) = delete; // required for singleton pattern
};

