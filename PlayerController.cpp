#pragma once
#include "PlayerController.h"
#include "Player.h"
/// <summary>
/// 
/// </summary>
/// <param name="player"></param>
PlayerController::PlayerController(Player* player)
{
    this->m_player = player;
}

/// <summary>
/// Called once per tick, prior to <see cref="PlayerController::eventUpdate"/>
/// </summary>
void PlayerController::preEventUpdate()
{
    //this->m_isMoveForwardKeyPressed = this->m_isMoveBackwardKeyPressed = this->m_isMoveLeftKeyPressed = this->m_isMoveRightKeyPressed = false;
}

/// <summary>
/// Checks if the provided <paramref name="pressedKeyCode"/> is present in the provided 
/// </summary>
/// <param name="pressedKeyCode">test</param>
/// <param name="keys"></param>
/// <returns></returns>
bool PlayerController::IsKeyInArray(const sf::Keyboard::Key &pressedKeyCode, sf::Keyboard::Key (&keys)[2])
{
    return std::find(std::begin(keys), std::end(keys), pressedKeyCode) != std::end(keys);
}

void PlayerController::eventUpdate(sf::Event& ev)
{
   
}

/// <summary>
/// Checks to see if any <see cref="sf::Keyboard::Key"/> in the provided array <paramref name="keys"/> is currently pressed.
/// </summary>
/// <param name="keys">A reference to an array of <see cref="sf::Keyboard::Key"/>s to be checked.</param>
/// <returns><see langword="true"/>, if one or more keys in the provided array <paramref name="keys"/> is pressed; otherwise, <see langword="false"/></returns>
bool PlayerController::IsAnyKeyPressed(sf::Keyboard::Key(&keys)[2])
{
    for (const auto& key : keys)
    {
        if (sf::Keyboard::isKeyPressed(key))
        {
            return true;
        }
    }

    return false;
}

void PlayerController::update(sf::Clock& deltaClock)
{
    float movementSpeed = 0.0f;
    float rotationSpeed = 0.0f;

    if (PlayerController::IsAnyKeyPressed(this->m_moveForwardKeys))
    {
        movementSpeed += ACCELERATION_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_moveBackwardKeys))
    {
        movementSpeed += DECCELERATION_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnLeftKeys))
    {
        rotationSpeed -= TURN_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnRightKeys))
    {
        rotationSpeed += TURN_SPEED;
    }
    //movementSpeed = std::clamp(movementSpeed, -PlayerController::MAX_SPEED, PlayerController::MAX_SPEED);
    //rotationSpeed = std::clamp(rotationSpeed, -PlayerController::MAX_SPEED, PlayerController::MAX_SPEED);

    this->m_player->addMovementSpeed(movementSpeed);
    this->m_player->addRotationSpeed(rotationSpeed);
}