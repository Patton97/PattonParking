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
    /*
    bool isKeyPressedEvent = ev.type == sf::Event::KeyPressed;
    bool isKeyReleasedEvent = ev.type == sf::Event::KeyReleased;
    bool isKeyEvent = isKeyPressedEvent || isKeyReleasedEvent;
    if (isKeyEvent)
    {
        if (PlayerController::IsKeyInArray(ev.key.code, this->m_moveForwardKeys))
        {
            this->m_isMoveForwardKeyPressed = true;
        }
        if (PlayerController::IsKeyInArray(ev.key.code, this->m_moveBackwardKeys))
        {
            this->m_isMoveBackwardKeyPressed = true;
        }
        if (PlayerController::IsKeyInArray(ev.key.code, this->m_turnLeftKeys))
        {
            this->m_isMoveLeftKeyPressed = true;
        }
        if (PlayerController::IsKeyInArray(ev.key.code, this->m_turnRightKeys))
        {
            this->m_isMoveRightKeyPressed = true;
        }
    }
    */
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
    sf::Vector2f* movementVector = new sf::Vector2f();

    if (PlayerController::IsAnyKeyPressed(this->m_moveForwardKeys))
    {
        movementVector->y += ACCELERATION_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_moveBackwardKeys))
    {
        movementVector->y += DECCELERATION_SPEED;
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnLeftKeys))
    {
        movementVector->x += -TURN_SPEED; // i know this is dumb its just temp
    }
    if (PlayerController::IsAnyKeyPressed(this->m_turnRightKeys))
    {
        movementVector->x += TURN_SPEED; // temp
    }
    movementVector->x = std::clamp(movementVector->x, -PlayerController::MAX_SPEED, PlayerController::MAX_SPEED);
    movementVector->y = std::clamp(movementVector->y, -PlayerController::MAX_SPEED, PlayerController::MAX_SPEED);

    this->m_player->addMovement(*movementVector);


    delete movementVector;
    movementVector = nullptr;
}