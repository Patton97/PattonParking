#define _USE_MATH_DEFINES
#include <math.h>
#include "CircleGizmo.h"

CircleGizmo::CircleGizmo(sf::Vector2f* origin, float radius)
{
    this->m_originV2f = origin;
    this->m_shape.setRadius(radius);
    this->m_shape.setOutlineColor(sf::Color::Green);
    this->m_shape.setFillColor(sf::Color::Transparent);
    this->m_shape.setOutlineThickness(1.0f);
}

CircleGizmo::~CircleGizmo()
{
}

void CircleGizmo::update(sf::Time& deltaTime)
{
    GameObject::update(deltaTime);
    this->m_shape.setPosition(*this->m_originV2f);
}

void CircleGizmo::renderGizmos(sf::RenderWindow& window)
{
    window.draw(this->m_shape);
}
