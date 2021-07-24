#pragma once

#include <iostream>
#include "Player.h"
#include "PlayerController.h"

Player::Player()
{
    this->m_image = new sf::Image();
    this->m_image->loadFromFile(".\\assets\\cars\\car-body\\car-body.png");
    
    this->m_texture = new sf::Texture();
    this->m_texture->loadFromImage(*this->m_image);

    this->m_sprite = new sf::Sprite(*this->m_texture);

    this->m_sprite->setPosition(10.0f, 10.0f);
    this->m_sprite->setOrigin(this->m_sprite->getTextureRect().width * 0.5f, this->m_sprite->getTextureRect().height * 0.5f);

    PlayerController* playerController = new PlayerController(*this->m_sprite);
    this->addComponent(*playerController);
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(*this->m_sprite);
}