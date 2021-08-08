#include "LineGizmo.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

LineGizmo::LineGizmo(GameObject* lineStart, GameObject* lineEnd)
{
    this->m_lineStart = lineStart;
    this->m_lineEnd = lineEnd;
    this->m_lineType = LineType::PointToPoint;
}

LineGizmo::LineGizmo(GameObject* lineStart, sf::Vector2f direction)
{
    this->m_lineStart = lineStart;
    this->setDirection(direction);
}

LineGizmo::~LineGizmo()
{
    delete this->m_lineStart;
    this->m_lineStart = nullptr;

    delete this->m_lineEnd;
    this->m_lineEnd = nullptr;
}

void LineGizmo::renderGizmos(sf::RenderWindow& window)
{
    sf::Vector2f lineStart = this->m_lineStart->getPosition();
    sf::Vector2f lineEnd = sf::Vector2f();
    
    switch (this->m_lineType)
    {
        case LineType::PointToPoint:
            lineEnd = this->m_lineEnd->getPosition();
            break;
        case LineType::InDirection:
            float angle_rads = this->m_lineStart->getRotation() * (M_PI / 180.0f); 
            lineEnd.x = this->m_lineStart->getPosition().x + (this->m_direction.x * cos(angle_rads));
            lineEnd.y = this->m_lineStart->getPosition().y + (this->m_direction.x * sin(angle_rads));
            break;
    }

    sf::Vertex points[] =
    {
        sf::Vertex(lineStart, sf::Color::Green),
        sf::Vertex(lineEnd, sf::Color::Green),
    };

    window.draw(points, 2, sf::Lines);
}

void LineGizmo::setDirection(sf::Vector2f direction)
{
    this->m_direction = direction;
    this->m_lineType = LineType::InDirection;
}
