#pragma once

#include <SFML/Graphics.hpp>

#include "..\GameObject.h"
#include "..\SpriteWrapper.h"

class CarWheelPrefab : public GameObject
{
public:
    CarWheelPrefab(GameObject* parent, sf::Vector2f positionOffset = sf::Vector2f(0.0f, 0.0f), float rotationOffset = 0.0f);
    ~CarWheelPrefab();
    void update(sf::Time& deltaTime) override;
    void render(sf::RenderWindow& window) override;
private:
    sf::Vector2f m_positionOffset = sf::Vector2f(0.0f, 0.0f);
    float m_rotationOffset = 0.0f;

    const std::string CAR_WHEEL_IMAGE_SOURCE = ".\\assets\\cars\\car-wheel\\car-wheel-16.png";
    SpriteWrapper* m_carWheel = new SpriteWrapper(CAR_WHEEL_IMAGE_SOURCE, this->m_transform);
};

