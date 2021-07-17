#pragma once
#include "Player.h"
#include "PlayerController.h"
#include <iostream>

Player::Player()
{
    this->m_image = new sf::Image();
    this->m_image->loadFromFile(".\\assets\\cars\\car-body\\car-body.png");
    
    this->m_texture = new sf::Texture();
    this->m_texture->loadFromImage(*this->m_image);

    this->m_sprite = new sf::Sprite(*this->m_texture);

    this->m_sprite->setPosition(10.0f, 10.0f);

    this->m_movementVector = new sf::Vector2f();

    this->m_controller = new PlayerController(this);
}

void Player::addMovement(const sf::Vector2f& addMovement)
{
    *this->m_movementVector += addMovement;
}

void Player::update(sf::RenderWindow& window, sf::Event& ev, sf::Clock& deltaClock)
{
    this->m_movementVector->x = this->m_movementVector->y = 0;
    this->m_controller->Update(deltaClock);
    *this->m_movementVector *= deltaClock.getElapsedTime().asSeconds();
    this->move();
    this->draw(window);
}

void Player::move()
{
    this->m_sprite->move(*this->m_movementVector);
    //std::cout << "(" << this->m_sprite->getPosition().x << ", " << this->m_sprite->getPosition().y << ")" << std::endl;
    //std::cout << "(" << this->m_movementVector->x << ", " << this->m_movementVector->y << ")" << std::endl;
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(*this->m_sprite);
}