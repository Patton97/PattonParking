#define _USE_MATH_DEFINES
#include <math.h>

#include "GameObject.h"
#include "CircleGizmo.h"


CircleGizmo::CircleGizmo(GameObject* origin, float radius)
{
    this->m_origin = origin;
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
    this->m_shape.setPosition(this->m_origin->getPosition());
}

void CircleGizmo::render(sf::RenderWindow& window)
{
    window.draw(this->m_shape);
}
