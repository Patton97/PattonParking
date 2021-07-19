#pragma once
#include "Updateable.h"
class GameComponent : Updateable
{
    public:
        virtual void update() override = 0;
};

