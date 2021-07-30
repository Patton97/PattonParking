#include "SpriteWrapper.h"

SpriteWrapper::SpriteWrapper(std::string imageSource, sf::Transformable* transform)
{
    this->setImage(imageSource);

    this->setTransform(transform);
}

SpriteWrapper::~SpriteWrapper()
{
    delete this->m_image;
    this->m_image = nullptr;

    delete this->m_texture;
    this->m_texture = nullptr;

    delete this->m_sprite;
    this->m_sprite = nullptr;

    delete this->m_transform;
    this->m_transform = nullptr;
}

void SpriteWrapper::render(sf::RenderWindow& window)
{
    this->m_sprite->setPosition(this->m_transform->getPosition());
    this->m_sprite->setRotation(this->m_transform->getRotation());

    window.draw(*this->m_sprite);
}

void SpriteWrapper::setImage(std::string imageSource)
{
    this->m_image = new sf::Image();
    this->m_image->loadFromFile(imageSource);

    this->m_texture = new sf::Texture();
    this->m_texture->loadFromImage(*this->m_image);

    this->m_sprite = new sf::Sprite(*this->m_texture);

    this->m_sprite->setOrigin(sf::Vector2f(this->m_texture->getSize()) * 0.5f);
}

void SpriteWrapper::setTransform(sf::Transformable* transform)
{
    this->m_transform = transform;
}
