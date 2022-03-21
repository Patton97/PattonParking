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
        static TimeKeeper& getInstance()
        {
            static TimeKeeper instance;
            return instance;
        }
        sf::Time& getDeltaTime();
    protected:
        void start() override;
        void update(sf::Time& deltaTime) override;
        void render(sf::RenderWindow& window) override;
    private:
        TimeKeeper() {}

        sf::Clock clock;
        sf::Time previousTime = sf::Time();
        sf::Time currentTime = sf::Time();
        sf::Time deltaTime = sf::Time::Zero;

    // required for singleton pattern
    public:
        TimeKeeper(TimeKeeper const&) = delete;
        void operator=(TimeKeeper const&) = delete;
};

