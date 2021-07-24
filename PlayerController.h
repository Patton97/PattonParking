#pragma once
#include <SFML\Window\Event.hpp>
#include <SFML\System.hpp>
#include <SFML\Graphics\Transformable.hpp>
#include "GameComponent.h"
class PlayerController : public GameComponent
{
    public:
#pragma region constructors/deconstructors
        PlayerController(sf::Transformable& player);
        ~PlayerController();
#pragma endregion

#pragma region member methods
        void preEventUpdate() override;
        void eventUpdate(sf::Event& ev) override;
        void update(sf::Time& deltaTime) override;
#pragma endregion

    private:
#pragma region static methods
        static bool IsKeyInArray(const sf::Keyboard::Key& pressedKeyCode, sf::Keyboard::Key(&keys)[2]);
        static bool IsAnyKeyPressed(sf::Keyboard::Key(&keys)[2]);
#pragma endregion

#pragma region member methods
        const float ACCELERATION_SPEED = 100.0f;
        const float DECCELERATION_SPEED = ACCELERATION_SPEED * -0.8f;
        const float TURN_SPEED = 100.0f;
#pragma endregion

#pragma region member variables
        sf::Keyboard::Key m_moveForwardKeys[2]{ sf::Keyboard::W, sf::Keyboard::Up };
        sf::Keyboard::Key m_moveBackwardKeys[2]{ sf::Keyboard::S, sf::Keyboard::Down };
        sf::Keyboard::Key m_turnLeftKeys[2]{ sf::Keyboard::A, sf::Keyboard::Left };
        sf::Keyboard::Key m_turnRightKeys[2]{ sf::Keyboard::D, sf::Keyboard::Right };
        sf::Transformable* m_player;
        float m_movementSpeed = 0.0f;
        float m_rotationSpeed = 0.0f;
#pragma endregion

};

