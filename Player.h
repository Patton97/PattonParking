#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerController.h"

class Player
{
    public:
        Player();
        void update(sf::RenderWindow& window, sf::Event& ev, sf::Clock& deltaClock);
        void render(sf::RenderWindow& window);
        void addMovement(const sf::Vector2f& addMovement);
        PlayerController* m_controller;

    private:
        sf::Image* m_image;
        sf::Texture* m_texture;
        sf::Sprite* m_sprite;
        sf::Vector2f* m_movementVector;

        void move();
};

