#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerController.h"
#include "GameObject.h"
#include "SpriteWrapper.h"

class Player : public GameObject
{
    public:
#pragma region Constructors/Deconstructors
        Player();
#pragma endregion
        
#pragma region Member Methods
        void update(sf::Time& deltaTime) override;
        void render(sf::RenderWindow& window) override;
#pragma endregion

    private:
#pragma region Member Variables
        const std::string CAR_BODY_IMAGE_SOURCE = ".\\assets\\cars\\car-body\\car-body.png";
        SpriteWrapper* m_carBody = new SpriteWrapper(CAR_BODY_IMAGE_SOURCE, this->m_transform);
#pragma endregion
};

