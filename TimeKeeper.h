#pragma once

#include <SFML\Graphics.hpp>

#include "GameObject.h"

/// <summary>
/// Keeps track of the time within the game. Other classes can call into here rather than trying to calculate it themselves.
/// </summary>
/// <remarks>Yes, this should probably be called "TimeManager" but I've been watching Loki recently and this was too good an opportunity to pass up</remarks>
class TimeKeeper : public GameObject
{
    public:
#pragma region Static Methods
        static TimeKeeper& getInstance()
        {
            static TimeKeeper instance;
            return instance;
        }
#pragma endregion

#pragma region Member Methods
        void start() override;
        void update(sf::Time& deltaTime) override;
        void render(sf::RenderWindow& window) override;
    
        sf::Time& getDeltaTime();
#pragma endregion

    private:
#pragma region Constructors/Desconstructors
        TimeKeeper()
        {
        
        }
#pragma endregion

#pragma region Member Variables
        sf::Clock clock;
        sf::Time previousTime = sf::Time();
        sf::Time currentTime = sf::Time();
        sf::Time deltaTime = sf::Time::Zero;
#pragma endregion

    public:
        TimeKeeper(TimeKeeper const&) = delete; // required for singleton pattern
        void operator=(TimeKeeper const&) = delete; // required for singleton pattern
};

