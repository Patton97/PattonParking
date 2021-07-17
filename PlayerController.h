#pragma once
#include <SFML\Window\Event.hpp>
#include <SFML\System.hpp>

class Player;

class PlayerController
{
    public:
        inline PlayerController(Player* player);
        inline void PreEventUpdate();
        inline void EventUpdate(sf::Event& ev);
        inline void Update(sf::Clock& deltaClock);

    private:
        const float MAX_SPEED = 1000.0f;
        const float ACCELERATION_SPEED = -1000.0f;
        const float DECCELERATION_SPEED = ACCELERATION_SPEED * -0.8f;
        const float TURN_SPEED = 10.0f;
        static inline bool IsKeyInArray(const sf::Keyboard::Key& pressedKeyCode, sf::Keyboard::Key(&keys)[2]);
        sf::Keyboard::Key m_moveForwardKeys[2] { sf::Keyboard::W, sf::Keyboard::Up };
        sf::Keyboard::Key m_moveBackwardKeys[2] { sf::Keyboard::S, sf::Keyboard::Down };
        sf::Keyboard::Key m_turnLeftKeys[2] { sf::Keyboard::A, sf::Keyboard::Left };
        sf::Keyboard::Key m_turnRightKeys[2] { sf::Keyboard::D, sf::Keyboard::Right };
        bool m_isMoveForwardKeyPressed = false , m_isMoveBackwardKeyPressed = false, m_isMoveLeftKeyPressed = false, m_isMoveRightKeyPressed = false;
        Player* m_player = nullptr;
};

