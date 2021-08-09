#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include "Player.h"
#include "PlayerController.h"

Player::Player()
{
    PlayerController* playerController = new PlayerController(this);
    this->addComponent(*playerController);
    playerController = nullptr;

    this->addChild(*this->m_carWheelFrontLeft);
    this->addChild(*this->m_carWheelFrontRight);
    this->addChild(*this->m_carWheelBackLeft);
    this->addChild(*this->m_carWheelBackRight);
    this->addChild(*this->m_carBody);
    this->addChild(*this->m_turningTriangleHypotenuse);
    this->addChild(*this->m_driveShaftGizmo);
    this->addChild(*this->m_frontAxleGizmo);
    this->addChild(*this->m_backAxleGizmo);
    this->addChild(*this->m_turningOriginGizmo);

    this->m_transform->setPosition(16.0f, 16.0f);
}

void Player::update(sf::Time& deltaTime)
{
    GameObject::update(deltaTime);
    this->m_carWheelFront->setRotationOffset(this->m_turnAmount);
    this->m_carWheelFrontLeft->setRotationOffset(this->m_turnAmount);
    this->m_carWheelFrontRight->setRotationOffset(this->m_turnAmount);

    float driveShaftLength = std::hypotf(this->m_carWheelFront->getPosition().x - this->m_carWheelBack->getPosition().x, this->m_carWheelFront->getPosition().y - this->m_carWheelBack->getPosition().y);
    this->m_turningTriangleHypotenuse->setDirection(sf::Vector2f(driveShaftLength, 0.0f));

    
    float tan_angle = tanf((M_PI / 180.0f) * this->m_turnAmount);
    sf::Vector2f turningOriginRelativeToBackWheel = sf::Vector2f(driveShaftLength / tan_angle, 0.0f);
    *this->m_turningOrigin = this->m_carWheelBack->getPosition() + turningOriginRelativeToBackWheel;
    this->m_transform->setOrigin(*this->m_turningOrigin);
    this->m_transform->rotate(tanf(this->m_turnAmount) * this->m_speed);
    this->m_transform->setOrigin(this->getPosition());
    std::cout << std::fabsf(this->m_turnAmount) << std::endl;
    
    float angle_rads = (M_PI / 180.0f) * (this->getRotation());
    float fwdX =  sin(angle_rads) * this->m_speed;
    float fwdY = -cos(angle_rads) * this->m_speed;

    this->m_transform->move(fwdX, fwdY);
}

void Player::setSpeed(float speed)
{
    this->m_speed = speed;
}

void Player::setTurnAmount(float turnAmount)
{
    this->m_turnAmount = turnAmount;
}

// TODO: Create a utilities class (surely this already exists somewhere in sfml or math.h?)
sf::Vector2f Player::GetMidpoint(sf::Vector2f v1, sf::Vector2f v2)
{
    return sf::Vector2f((v1.x + v2.x) * 0.5f, (v1.y + v2.y) * 0.5f);
}
