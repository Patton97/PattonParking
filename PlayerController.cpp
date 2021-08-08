#pragma once

#include <iostream>

#include "PlayerController.h"


/// <summary>
/// 
/// </summary>
/// <param name="player"></param>
PlayerController::PlayerController(Player* player)
{
    this->m_player = player;
}

PlayerController::~PlayerController()
{
    delete this->m_player;
    this->m_player = nullptr;
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

void PlayerController::update(sf::Time& deltaTime)
{
    this->updateSpeed(deltaTime);
    this->updateRotation(deltaTime);
}

void PlayerController::updateSpeed(sf::Time& deltaTime)
{
    this->m_movementSpeed = 0;
    if (PlayerController::IsAnyKeyPressed(this->m_moveForwardKeys))
    {
        this->m_movementSpeed += ACCELERATION_SPEED * deltaTime.asSeconds();
    }
    if (PlayerController::IsAnyKeyPressed(this->m_moveBackwardKeys))
    {
        this->m_movementSpeed += DECCELERATION_SPEED * deltaTime.asSeconds();
    }
    this->m_player->setSpeed(this->m_movementSpeed);
}

void PlayerController::updateRotation(sf::Time& deltaTime)
{
    if (PlayerController::IsAnyKeyPressed(this->m_turnLeftKeys))
    {
        this->m_turnAmount -= TURN_SPEED * deltaTime.asSeconds();
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnRightKeys))
    {
        this->m_turnAmount += TURN_SPEED * deltaTime.asSeconds();
    }
    this->m_turnAmount = std::clamp(this->m_turnAmount, MIN_TURN_AMOUNT, MAX_TURN_AMOUNT);
    this->m_player->setTurnAmount(this->m_turnAmount);
}
