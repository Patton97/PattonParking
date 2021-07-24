#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerController.h"

class Player
{
    public:
        // constructor
        Player();
        // methods
        void update(sf::RenderWindow& window, sf::Event& ev, sf::Clock& deltaClock);
        void render(sf::RenderWindow& window);
        void addMovementSpeed(float amount);
        void addRotationSpeed(float amount);
        // variables
        PlayerController* m_controller;

    private:
        // methods
        void updateMovement(sf::Clock& deltaClock);
        void updateRotation(sf::Clock& deltaClock);
        // variables
        sf::Image* m_image;
        sf::Texture* m_texture;
        sf::Sprite* m_sprite;
        float m_movementSpeed;
        float m_rotationSpeed;
};

