#pragma once

#include <iostream>
#include <math.h>
#include "Player.h"
#include "PlayerController.h"

#define _USE_MATH_DEFINES

Player::Player()
{
    this->m_image = new sf::Image();
    this->m_image->loadFromFile(".\\assets\\cars\\car-body\\car-body.png");
    
    this->m_texture = new sf::Texture();
    this->m_texture->loadFromImage(*this->m_image);

    this->m_sprite = new sf::Sprite(*this->m_texture);

    this->m_sprite->setPosition(10.0f, 10.0f);
    this->m_sprite->setOrigin(this->m_sprite->getTextureRect().width * 0.5f, this->m_sprite->getTextureRect().height * 0.5f);

    this->m_rotationSpeed = 0.0f;
    this->m_movementSpeed = 0.0f;

    this->m_controller = new PlayerController(this);
}

void Player::addMovementSpeed(float amount)
{
    this->m_movementSpeed += amount;
}

void Player::addRotationSpeed(float amount)
{
    this->m_rotationSpeed += amount;
}

void Player::update(sf::RenderWindow& window, sf::Event& ev, sf::Clock& deltaClock)
{
    this->m_controller->update(deltaClock);
    this->updateRotation(deltaClock);
    this->updateMovement(deltaClock);
}

void Player::updateRotation(sf::Clock& deltaClock)
{
    this->m_sprite->rotate(this->m_rotationSpeed *= deltaClock.getElapsedTime().asSeconds());
    //std::cout << "Rotating: " << this->m_rotationSpeed * deltaClock.getElapsedTime().asSeconds() << std::endl;
}

void Player::updateMovement(sf::Clock& deltaClock)
{
    //M_PI
    float angleRADS = (3.1415926536f / 180.0f) * (this->m_sprite->getRotation());

    float fwdX = sin(angleRADS) * m_movementSpeed * deltaClock.getElapsedTime().asSeconds();
    float fwdY = -cos(angleRADS) * m_movementSpeed * deltaClock.getElapsedTime().asSeconds();

    //std::cout << "Moving: (" << fwdX << ", " << fwdY << ")" << std::endl;
    
    //this->m_movementSpeed *= deltaClock.getElapsedTime().asSeconds()
    this->m_sprite->move(fwdX, fwdY);
    //std::cout << "(" << this->m_sprite->getPosition().x << ", " << this->m_sprite->getPosition().y << ")" << std::endl;
    //std::cout << "(" << this->m_movementVector->x << ", " << this->m_movementVector->y << ")" << std::endl;

    this->m_movementSpeed = 0;
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(*this->m_sprite);
}