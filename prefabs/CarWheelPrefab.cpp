#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "CarWheelPrefab.h"

CarWheelPrefab::CarWheelPrefab(GameObject* parent, sf::Vector2f positionOffset, float rotationOffset)
{
    this->setParent(parent);
    this->m_positionOffset = positionOffset;
    this->m_rotationOffset = rotationOffset;
    this->addChild(*this->m_rectangleGizmo);
}

CarWheelPrefab::~CarWheelPrefab()
{

}

void CarWheelPrefab::update(sf::Time& deltaTime)
{
    GameObject::update(deltaTime);

    // update transform, relative to parent
    sf::Vector2f newPosition = this->m_parent->getPosition();
    
    float angle_rads = (M_PI / 180) * (this->m_parent->getRotation());
    
    newPosition.x += this->m_positionOffset.x * cos(angle_rads) - this->m_positionOffset.y * sin(angle_rads);
    newPosition.y += this->m_positionOffset.x * sin(angle_rads) + this->m_positionOffset.y * cos(angle_rads);

    this->m_transform->setPosition(newPosition);

    this->m_transform->setRotation(this->m_parent->getRotation() + this->m_rotationOffset);

    //std::cout << "RotOffset: " << this->m_rotationOffset << std::endl;
}

void CarWheelPrefab::render(sf::RenderWindow& window)
{
    this->m_carWheel->render(window);
}
