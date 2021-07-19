#pragma once
#include <SFML\Window\Event.hpp>
#include <SFML\System.hpp>

class Player;

class PlayerController
{
    public:
        PlayerController(Player* player);
        void preEventUpdate();
        void eventUpdate(sf::Event& ev);
        void update(sf::Clock& deltaClock);

    private:
        const float MAX_SPEED = 1000.0f;
        const float ACCELERATION_SPEED = -1000.0f;
        const float DECCELERATION_SPEED = ACCELERATION_SPEED * -0.8f;
        const float TURN_SPEED = 10.0f;
        static bool IsKeyInArray(const sf::Keyboard::Key& pressedKeyCode, sf::Keyboard::Key(&keys)[2]);
        static bool IsAnyKeyPressed(sf::Keyboard::Key(&keys)[2]);
        sf::Keyboard::Key m_moveForwardKeys[2] { sf::Keyboard::W, sf::Keyboard::Up };
        sf::Keyboard::Key m_moveBackwardKeys[2] { sf::Keyboard::S, sf::Keyboard::Down };
        sf::Keyboard::Key m_turnLeftKeys[2] { sf::Keyboard::A, sf::Keyboard::Left };
        sf::Keyboard::Key m_turnRightKeys[2] { sf::Keyboard::D, sf::Keyboard::Right };
        Player* m_player = nullptr;
};

