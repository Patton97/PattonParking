#include "LineGizmo.h"
#include <math.h>
#include <iostream>

LineGizmo::LineGizmo(sf::Vector2f* lineStart, sf::Vector2f* lineEnd)
{
    this->m_lineStart = lineStart;
    this->m_lineEnd = lineEnd;
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
    sf::Vertex points[] =
    {
        sf::Vertex(*this->m_lineStart, sf::Color::Green),
        sf::Vertex(*this->m_lineEnd, sf::Color::Green)
    };

    window.draw(points, 2, sf::Lines);
}
