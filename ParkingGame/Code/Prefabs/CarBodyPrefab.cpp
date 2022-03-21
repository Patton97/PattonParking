#include "CarBodyPrefab.h"

CarBodyPrefab::CarBodyPrefab(GameObject* parent, sf::Vector2f positionOffset, float rotationOffset)
{
    this->setParent(parent);
    this->m_positionOffset = positionOffset;
    this->m_rotationOffset = rotationOffset;
}

CarBodyPrefab::~CarBodyPrefab()
{

}

void CarBodyPrefab::update(sf::Time& deltaTime)
{
    GameObject::update(deltaTime);

    // update transform, relative to parent
    this->m_transform->setPosition(this->m_parent->getPosition() + this->m_positionOffset);
    this->m_transform->setRotation(this->m_parent->getRotation() + this->m_rotationOffset);
}

void CarBodyPrefab::render(sf::RenderWindow& window)
{
    this->m_carBody->render(window);
}
