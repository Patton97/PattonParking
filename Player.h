#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerController.h"
#include "GameObject.h"

class Player : public GameObject
{
    public:
#pragma region Constructors/Deconstructors
        Player();
#pragma endregion
        
#pragma region Member Methods
        void render(sf::RenderWindow& window) override;
#pragma endregion

    private:
#pragma region Member Variables
        sf::Image* m_image;
        sf::Texture* m_texture;
        sf::Sprite* m_sprite;
#pragma endregion
};

