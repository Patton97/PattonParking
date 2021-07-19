#pragma once
#include <vector>
#include "Updateable.h"
#include "GameComponent.h"
class GameObject : Updateable
{
    public: 
        virtual void update();
    private:
        std::vector<GameComponent> components = {};
};

