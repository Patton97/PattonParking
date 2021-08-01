#pragma once

#include <iostream>
#include "Player.h"
#include "PlayerController.h"

Player::Player()
{
    PlayerController* playerController = new PlayerController(*this->m_transform);
    this->addComponent(*playerController);
    playerController = nullptr;

    CarWheelPrefab* m_carWheelFrontLeft = new CarWheelPrefab(this, sf::Vector2f(-14.0f, -16.0f));
    this->addChild(*m_carWheelFrontLeft);
    m_carWheelFrontLeft = nullptr;

    CarWheelPrefab* m_carWheelFrontRight = new CarWheelPrefab(this, sf::Vector2f(14.0f, -16.0f));
    this->addChild(*m_carWheelFrontRight);
    m_carWheelFrontRight = nullptr;

    CarWheelPrefab* m_carWheelBackLeft = new CarWheelPrefab(this, sf::Vector2f(-14.0f, 16.0f));
    this->addChild(*m_carWheelBackLeft);
    m_carWheelBackLeft = nullptr;

    CarWheelPrefab* m_carWheelBackRight = new CarWheelPrefab(this, sf::Vector2f(14.0f, 16.0f));
    this->addChild(*m_carWheelBackRight);
    m_carWheelBackRight = nullptr;

    CarBodyPrefab* m_carBody = new CarBodyPrefab(this);
    this->addChild(*m_carBody);
    m_carBody = nullptr;
}
