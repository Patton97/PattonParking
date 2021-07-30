#pragma once

#include <iostream>
#include "Player.h"
#include "PlayerController.h"

Player::Player()
{
    PlayerController* playerController = new PlayerController(*this->m_transform);
    this->addComponent(*playerController);
}

void Player::update(sf::Time& deltaTime)
{
    GameObject::update(deltaTime);
}

void Player::render(sf::RenderWindow& window)
{
    this->m_carBody->render(window);
    //window.draw(*this->m_carBodySprite);
}