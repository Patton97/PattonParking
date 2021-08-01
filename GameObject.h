#pragma once

#include <vector>

#include <SFML\Graphics\Transformable.hpp>

#include "Updateable.h"
#include "Renderable.h"
#include "GameComponent.h"

class GameObject : public Updateable, public Renderable
{
    public:
        virtual void start() {};
        virtual void update(sf::Time& deltaTime) override
        {
            for (auto& component : this->m_components)
            {
                component->update(deltaTime);
            }
            for (auto& child : this->m_children)
            {
                child->update(deltaTime);
            }
        }
        virtual void render(sf::RenderWindow& window)
        {
            for (auto& child : this->m_children)
            {
                child->render(window);
            }
        }


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

        void setParent(GameObject* parent)
        {
            // clear existing parent (if present)
            if (this->m_parent != nullptr)
            {
                parent->removeChild(*this);
            }
            // tell new parent to add [this] as a child
            parent->addChild(*this);
        }
        void addChild(GameObject& child)
        {
            child.m_parent = this;
            this->m_children.push_back(&child);
        }
        void removeChild(GameObject& child)
        {
            this->m_children.erase(std::remove(this->m_children.begin(), this->m_children.end(), &child), this->m_children.end());
            child.m_parent = nullptr;
        }
    protected:
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
        std::vector<GameComponent*> m_components = {};
        std::vector<GameObject*> m_children = {};
};

