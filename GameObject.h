#pragma once

#include <vector>

#include <SFML\Graphics\Transformable.hpp>

#include "Updateable.h"
#include "Renderable.h"
#include "GameComponent.h"

class GameObject : public Updateable, public Renderable
{
    friend class GameManager;
    public:
        const sf::Transform& getTransform()
        {
            return this->m_transform->getTransform();
        }
        const sf::Vector2f& getPosition()
        {
            return this->m_transform->getPosition();
        }
        float getRotation()
        {
            return this->m_transform->getRotation();
        }

        void setParent(GameObject* parent);
        void addChild(GameObject& child);
        void removeChild(GameObject& child);

    protected:
        virtual void start() {};
        virtual void update(sf::Time& deltaTime) override;
        virtual void render(sf::RenderWindow& window) override;
        virtual void renderGizmos(sf::RenderWindow& window);

        void addComponent(GameComponent& componentToAdd)
        {
            this->m_components.push_back(&componentToAdd);
        }
        void removeComponent(GameComponent& componentToAdd)
        {
            this->m_components.push_back(&componentToAdd);
        }
        sf::Transformable* m_transform = new sf::Transformable();
        GameObject* m_parent = nullptr;
    private:
        std::vector<GameObject*> m_children = {};
        std::vector<GameComponent*> m_components = {};
};

