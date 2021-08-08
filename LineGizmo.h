#pragma once
#include "GameObject.h"
class LineGizmo : public GameObject
{
    public:
        LineGizmo(sf::Vector2f* lineStart, sf::Vector2f* lineEnd);
        ~LineGizmo();
        void renderGizmos(sf::RenderWindow& window) override;
    private:
        sf::Vector2f* m_lineStart = nullptr;
        sf::Vector2f* m_lineEnd = nullptr;
};

