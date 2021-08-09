#pragma once

#include "SFML\Graphics\CircleShape.hpp"
#include "SFML\Graphics\Vertex.hpp"

class CircleGizmo : public GameObject
{
    public:
        CircleGizmo(GameObject* origin, float radius);
        CircleGizmo(sf::Vector2f* origin, float radius);
        ~CircleGizmo();
        void update(sf::Time& deltaTime) override;
        void renderGizmos(sf::RenderWindow& window) override;
    private:
        sf::CircleShape m_shape = sf::CircleShape(); 
        GameObject* m_origin = nullptr;
        sf::Vector2f* m_originV2f = nullptr;
        float m_radius = 0.0f;
};

