#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "PlayerController.h"
#include "Player.h"

/// <summary>
/// 
/// </summary>
/// <param name="player"></param>
PlayerController::PlayerController(sf::Transformable& player)
{
    this->m_player = &player;
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
    //TODO: this->updateMovementAndRotation();

    if (PlayerController::IsAnyKeyPressed(this->m_moveForwardKeys))
    {
        this->m_movementSpeed += ACCELERATION_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_moveBackwardKeys))
    {
        this->m_movementSpeed += DECCELERATION_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnLeftKeys))
    {
        this->m_turnAmount -= TURN_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnRightKeys))
    {
        this->m_turnAmount += TURN_SPEED;
    }

    this->m_turnAmount = std::clamp(this->m_turnAmount, MIN_TURN_AMOUNT, MAX_TURN_AMOUNT);

    float angleRADS = (M_PI / 180.0f) * (this->m_player->getRotation());

    float fwdX = sin(angleRADS) * m_movementSpeed * deltaTime.asSeconds();
    float fwdY = -cos(angleRADS) * m_movementSpeed * deltaTime.asSeconds();

    this->m_player->move(fwdX, fwdY);

    this->m_player->rotate(this->m_turnAmount *= deltaTime.asSeconds());

    this->m_movementSpeed = 0.0f;
}