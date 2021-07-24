#pragma once

#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

class Updateable
{
    public:
        virtual void preEventUpdate() {};
        virtual void eventUpdate(sf::Event& ev) {};
        virtual void update(sf::Time& deltaTime) {};
};

