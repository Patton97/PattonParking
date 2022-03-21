#pragma once
#include "../GameObject.h"
class LineGizmo : public GameObject
{
    public:
        LineGizmo(GameObject* lineStart, GameObject* lineEnd, sf::Color colour = sf::Color::Green);
        LineGizmo(GameObject* lineStart, sf::Vector2f direction, sf::Color colour = sf::Color::Green);
        ~LineGizmo();
        void renderGizmos(sf::RenderWindow& window) override;
        void setDirection(sf::Vector2f direction);
    private:
        enum class LineType { PointToPoint, InDirection };
        LineType m_lineType;
        GameObject* m_lineStart = nullptr;
        GameObject* m_lineEnd = nullptr;
        sf::Vector2f m_direction = sf::Vector2f();
        sf::Color m_colour = sf::Color();
};

