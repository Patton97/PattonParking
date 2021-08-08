#include "RectangleGizmo.h"

RectangleGizmo::RectangleGizmo(float width, float height)
{
    this->m_shape.setOutlineColor(sf::Color::Green);
    this->m_shape.setFillColor(sf::Color::Transparent);
    this->m_shape.setOutlineThickness(1.0f);
    this->m_shape.setSize(sf::Vector2f(width, height));
    this->m_shape.setOrigin(width * 0.5f, height * 0.5f);
}

RectangleGizmo::~RectangleGizmo()
{
}

void RectangleGizmo::update(sf::Time& deltaTime)
{
    this->m_shape.setPosition(this->m_parent->getPosition());
    this->m_shape.setRotation(this->m_parent->getRotation());
}

void RectangleGizmo::renderGizmos(sf::RenderWindow& window)
{
    window.draw(this->m_shape);
}
