#pragma once

#include <SFML/Graphics.hpp>

#include <Engine/GameObject.h>
#include <Engine/SpriteWrapper.h>

class CarBodyPrefab : public GameObject
{
    public:
        CarBodyPrefab(GameObject* parent, sf::Vector2f positionOffset = sf::Vector2f(0.0f, 0.0f), float rotationOffset = 0.0f);
        ~CarBodyPrefab();
        void render(sf::RenderWindow& window) override;
    protected:
        void update(sf::Time& deltaTime) override;
        
    private:
        sf::Vector2f m_positionOffset = sf::Vector2f(0.0f, 0.0f);
        float m_rotationOffset = 0.0f;

        const std::string CAR_BODY_IMAGE_SOURCE = ".\\assets\\cars\\car-body\\car-body-64.png";
        SpriteWrapper* m_carBody = new SpriteWrapper(CAR_BODY_IMAGE_SOURCE, this->m_transform);
};

