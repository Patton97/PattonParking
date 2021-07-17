#pragma once
#include <SFML/Graphics.hpp>

class PlayerController;

class Player
{
    public:
        inline Player();
        inline void update(sf::RenderWindow& window, sf::Event& ev, sf::Clock& deltaClock);
        inline void addMovement(const sf::Vector2f& addMovement);

        PlayerController* m_controller;

    private:
        sf::Image* m_image;
        sf::Texture* m_texture;
        sf::Sprite* m_sprite;
        sf::Vector2f* m_movementVector;

        inline void move();
        inline void draw(sf::RenderWindow& window);
};

