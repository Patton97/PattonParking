#pragma once

#include "SFML\Graphics\RectangleShape.hpp"

#include "../GameObject.h"

class RectangleGizmo : public GameObject
{
    public:
        RectangleGizmo(float width, float height);
        ~RectangleGizmo();
        void renderGizmos(sf::RenderWindow& window) override;
        void update(sf::Time& deltaTime) override;
    private:
        sf::RectangleShape m_shape = sf::RectangleShape(sf::Vector2f(10,10));
};

