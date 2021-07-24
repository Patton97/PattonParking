#pragma once
#include <vector>

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
        }
    protected:
        void addComponent(GameComponent& componentToAdd)
        {
            this->m_components.push_back(&componentToAdd);
        }
    private:
        std::vector<GameComponent*> m_components = {};
};

