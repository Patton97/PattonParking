#pragma once
#include "Renderable.h"
#include <SFML\Graphics.hpp>

class SpriteWrapper : Renderable
{
    public:
        SpriteWrapper(std::string imageSource, sf::Transformable* transform);
        ~SpriteWrapper();
        void render(sf::RenderWindow& window) override;
        void setImage(std::string imageSource);
        void setTransform(sf::Transformable* transform);
        sf::IntRect getRect()
        {
            return this->m_sprite->getTextureRect();
        }
    private:
        sf::Image* m_image = nullptr;
        sf::Texture* m_texture = nullptr;
        sf::Sprite* m_sprite = nullptr;
        sf::Transformable* m_transform = nullptr;
};

