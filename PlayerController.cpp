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
/// Called once per tick, prior to <see cref="PlayerController::EventUpdate"/>
/// </summary>
void PlayerController::PreEventUpdate()
{
    this->m_isMoveForwardKeyPressed = this->m_isMoveBackwardKeyPressed = this->m_isMoveLeftKeyPressed = this->m_isMoveRightKeyPressed = false;
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

void PlayerController::EventUpdate(sf::Event& ev)
{
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
    
}

void PlayerController::Update(sf::Clock& deltaClock)
{
    sf::Vector2f* movementVector = new sf::Vector2f();

    if (this->m_isMoveForwardKeyPressed)
    {
        movementVector->y += ACCELERATION_SPEED;
    }
    if (this->m_isMoveBackwardKeyPressed)
    {
        movementVector->y += DECCELERATION_SPEED;
    }
    if (this->m_isMoveLeftKeyPressed)
    {
        movementVector->x += -TURN_SPEED; // i know this is dumb its just temp
    }
    if (this->m_isMoveRightKeyPressed)
    {
        movementVector->x += TURN_SPEED; // temp
    }
    movementVector->x = std::clamp(movementVector->x, -PlayerController::MAX_SPEED, PlayerController::MAX_SPEED);
    movementVector->y = std::clamp(movementVector->y, -PlayerController::MAX_SPEED, PlayerController::MAX_SPEED);

    this->m_player->addMovement(*movementVector);


    delete movementVector;
    movementVector = nullptr;
}