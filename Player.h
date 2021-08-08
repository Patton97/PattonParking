#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"

#include "prefabs\CarBodyPrefab.h"
#include "prefabs\CarWheelPrefab.h"
#include "CircleGizmo.h"
#include "LineGizmo.h"

class Player : public GameObject
{
#pragma region Constructors/Deconstructors
    public:
        Player();
#pragma endregion
        
#pragma region Member Methods
    public:
        void setSpeed(float speed);
        void setTurnAmount(float turnAmount);
        void update(sf::Time& deltaTime) override;
    private:
        static sf::Vector2f GetMidpoint(sf::Vector2f v1, sf::Vector2f v2);
#pragma endregion

#pragma region Member Variables
    public:
    private:
        float m_speed = 0.0f;
        float m_turnAmount = 0.0f;

        CarBodyPrefab*  m_carBody = new CarBodyPrefab(this);
        CarWheelPrefab* m_carWheelFrontLeft  = new CarWheelPrefab(this, sf::Vector2f(-14.0f, -16.0f));
        CarWheelPrefab* m_carWheelFrontRight = new CarWheelPrefab(this, sf::Vector2f( 14.0f, -16.0f));
        CarWheelPrefab* m_carWheelBackLeft   = new CarWheelPrefab(this, sf::Vector2f(-14.0f,  16.0f));
        CarWheelPrefab* m_carWheelBackRight  = new CarWheelPrefab(this, sf::Vector2f( 14.0f,  16.0f));
        CircleGizmo* m_frontWheelToHypotenuse = new CircleGizmo(this);

        sf::Vector2f* m_carAxleFrontMidpoint = new sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f* m_carAxleBackMidpoint = new sf::Vector2f(0.0f, 0.0f);
        LineGizmo* m_driveShaftGizmo = new LineGizmo(m_carAxleFrontMidpoint, m_carAxleBackMidpoint);
        sf::Vector2f* m_carWheelFrontLeftPosition = new sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f* m_carWheelFrontRightPosition = new sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f* m_carWheelBackLeftPosition = new sf::Vector2f(0.0f, 0.0f);
        sf::Vector2f* m_carWheelBackRightPosition = new sf::Vector2f(0.0f, 0.0f);
        LineGizmo* m_frontAxleGizmo = new LineGizmo(this->m_carWheelFrontLeftPosition, this->m_carWheelFrontRightPosition);
        LineGizmo* m_backAxleGizmo = new LineGizmo(this->m_carWheelBackLeftPosition, this->m_carWheelBackRightPosition);
#pragma endregion
};

