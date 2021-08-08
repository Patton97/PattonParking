#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"

#include "prefabs\CarBodyPrefab.h"
#include "prefabs\CarWheelPrefab.h"
#include "CircleGizmo.h"
#include "LineGizmo.h"

class Player : public GameObject
{
    public:
        Player();
        void setSpeed(float speed);
        void setTurnAmount(float turnAmount);
    protected: 
        void update(sf::Time& deltaTime) override;
    private:
        static sf::Vector2f GetMidpoint(sf::Vector2f v1, sf::Vector2f v2);

        float m_speed = 0.0f;
        float m_turnAmount = 0.0f;

        // TODO: All these positions offsets should be driven by constants or relative to other GO positions
        CarBodyPrefab*  m_carBody = new CarBodyPrefab(this);
        CarWheelPrefab* m_carWheelFront      = new CarWheelPrefab(this, sf::Vector2f(  0.0f, -16.0f));
        CarWheelPrefab* m_carWheelFrontLeft  = new CarWheelPrefab(this, sf::Vector2f(-14.0f, -16.0f));
        CarWheelPrefab* m_carWheelFrontRight = new CarWheelPrefab(this, sf::Vector2f( 14.0f, -16.0f));
        CarWheelPrefab* m_carWheelBack       = new CarWheelPrefab(this, sf::Vector2f(  0.0f,  16.0f));
        CarWheelPrefab* m_carWheelBackLeft   = new CarWheelPrefab(this, sf::Vector2f(-14.0f,  16.0f));
        CarWheelPrefab* m_carWheelBackRight  = new CarWheelPrefab(this, sf::Vector2f( 14.0f,  16.0f));

        /// <summary>
        /// A line gizmo visualising the hypotenuse of the 'turning triangle', as seen in fig 3 from
        /// <see href="https://www.researchgate.net/publication/323722783_A_Tutorial_On_Autonomous_Vehicle_Steering_Controller_Design_Simulation_and_Implementation">
        ///     'A Tutorial On Autonomous Vehicle Steering Controller Design, Simulation and Implementation'
        /// </see>
        /// </summary>
        LineGizmo* m_turningTriangleHypotenuse = new LineGizmo(this->m_carWheelFront, sf::Vector2f(20.0f, 0.0f));
        LineGizmo* m_driveShaftGizmo = new LineGizmo(this->m_carWheelFront, this->m_carWheelBack);
        LineGizmo* m_frontAxleGizmo = new LineGizmo(this->m_carWheelFrontLeft, this->m_carWheelFrontRight);
        LineGizmo* m_backAxleGizmo = new LineGizmo(this->m_carWheelBackLeft, this->m_carWheelBackRight);
#pragma endregion
};

