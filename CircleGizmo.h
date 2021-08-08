#pragma once

#include "SFML/Graphics/Vertex.hpp"

#include "GameObject.h"

class CircleGizmo : public GameObject
{
public:
    CircleGizmo(GameObject* parent, sf::Vector2f positionOffset = sf::Vector2f(0.0f, 0.0f), float rotationOffset = 0.0f);
    ~CircleGizmo();
    void update(sf::Time& deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void setPositionOffset(sf::Vector2f positionOffset)
    {
        this->m_positionOffset = positionOffset;
    }
    void setRotationOffset(float rotationOffset)
    {
        this->m_rotationOffset = rotationOffset;
    }
private:
    sf::Vector2f m_positionOffset = sf::Vector2f(0.0f, 0.0f);
    float m_rotationOffset = 0.0f;
    sf::Vertex point;
};

