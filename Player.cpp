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
    this->addChild(*this->m_frontWheelToHypotenuse);
    this->addChild(*this->m_driveShaftGizmo);
    this->addChild(*this->m_frontAxleGizmo);
    this->addChild(*this->m_backAxleGizmo);

    this->m_transform->setPosition(16.0f, 16.0f);
}

void Player::update(sf::Time& deltaTime)
{
    GameObject::update(deltaTime);

    this->m_carWheelFrontLeft->setRotationOffset(this->m_turnAmount);
    this->m_carWheelFrontRight->setRotationOffset(this->m_turnAmount);

    // update the axle midpoints
    *this->m_carAxleFrontMidpoint = Player::GetMidpoint(this->m_carWheelFrontLeft->getPosition(), this->m_carWheelFrontRight->getPosition());
    *this->m_carAxleBackMidpoint = Player::GetMidpoint(this->m_carWheelBackLeft->getPosition(), this->m_carWheelBackRight->getPosition());
    *this->m_carWheelFrontLeftPosition = this->m_carWheelFrontLeft->getPosition();
    *this->m_carWheelFrontRightPosition = this->m_carWheelFrontRight->getPosition();
    *this->m_carWheelBackLeftPosition = this->m_carWheelBackLeft->getPosition();
    *this->m_carWheelBackRightPosition = this->m_carWheelBackRight->getPosition();


    float frontWheelAngleEuler = this->m_carWheelFrontLeft->getRotation() + this->m_turnAmount;
    float frontWheelAngleRads = (M_PI / 180.0f) * frontWheelAngleEuler;
    sf::Vector2f frontWheelToTurnOriginVector = sf::Vector2f(cos(frontWheelAngleRads), -sin(frontWheelAngleRads));
    this->m_frontWheelToHypotenuse->setPositionOffset(frontWheelToTurnOriginVector);

    //std::cout << "fwtotoV = " << frontWheelToTurnOriginVector.x << ", " << frontWheelToTurnOriginVector.y << std::endl;

    float backWheelAngleEuler = this->m_carWheelBackLeft->getRotation();
    float backWheelAngleRads = (M_PI / 180.0f) * backWheelAngleEuler;
    sf::Vector2f backWheelToTurnOriginVector = sf::Vector2f(cos(backWheelAngleRads), -sin(backWheelAngleRads));

    // d(a,b) = sqrt((b.x - a.x)^2 + (b.y - a.y)^2)
    sf::Vector2f frontWheelMidpoint = Player::GetMidpoint(this->m_carWheelFrontLeft->getPosition(), this->m_carWheelFrontRight->getPosition());
    sf::Vector2f backWheelMidpoint = Player::GetMidpoint(this->m_carWheelBackLeft->getPosition(), this->m_carWheelBackRight->getPosition());
    float frontToBackWheelDistance = sqrtf(powf(frontWheelMidpoint.x - backWheelMidpoint.x, 2) + powf(frontWheelMidpoint.y - backWheelMidpoint.y, 2));
    
    // get the angle of the front wheel's transform.right vs the center axle
    //acosf(this->frontWheelToTurnOriginVector * frontWheelMidpoint)


    //V.x = cos(A)
    //V.y = sin(A)

    // OLD CAR MOVEMENT CODE
    float angleRADS = (M_PI / 180.0f) * (this->m_transform->getRotation());

    float fwdX =  sin(angleRADS) * this->m_speed;
    float fwdY = -cos(angleRADS) * this->m_speed;

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
