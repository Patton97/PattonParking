#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
class Renderable
{
    friend class GameManager;
    friend class GameObject;

    public:
        // left public because sprite wrappers need to access it and apparently granted friendships aren't inherited
        // TODO: surely there's a nice solution?
        virtual void render(sf::RenderWindow& window) {};
};

