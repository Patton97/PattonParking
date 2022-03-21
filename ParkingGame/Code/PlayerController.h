#pragma once
#include <SFML\Window\Event.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics\Transformable.hpp>

#include <Engine/GameComponent.h>

#include "Player.h"

class PlayerController : public GameComponent
{
    public:
        PlayerController(Player* player);
        ~PlayerController();
    protected:
        void eventUpdate(sf::Event& ev) override;
        void update(sf::Time& deltaTime) override;
    private:
        static bool IsKeyInArray(const sf::Keyboard::Key& pressedKeyCode, sf::Keyboard::Key(&keys)[2]);
        static bool IsAnyKeyPressed(sf::Keyboard::Key(&keys)[2]); 
        
        void updateSpeed(sf::Time& deltaTime);
        void updateRotation(sf::Time& deltaTime);

        const float ACCELERATION_SPEED = 100.0f;
        const float DECCELERATION_SPEED = ACCELERATION_SPEED * -0.8f;
        const float TURN_SPEED = 100.0f;
        const float MAX_TURN_AMOUNT = 45.0f;
        const float MIN_TURN_AMOUNT = -MAX_TURN_AMOUNT;

        sf::Keyboard::Key m_moveForwardKeys[2]{ sf::Keyboard::W, sf::Keyboard::Up };
        sf::Keyboard::Key m_moveBackwardKeys[2]{ sf::Keyboard::S, sf::Keyboard::Down };
        sf::Keyboard::Key m_turnLeftKeys[2]{ sf::Keyboard::A, sf::Keyboard::Left };
        sf::Keyboard::Key m_turnRightKeys[2]{ sf::Keyboard::D, sf::Keyboard::Right };
        Player* m_player = nullptr;
        float m_movementSpeed = 0.0f;
        float m_turnAmount = 0.0f;
};

