#pragma once
#include <SFML/Graphics/Transform.hpp>

#include "Updateable.h"

class Dummy : public Updateable
{
public:
    const sf::Transform& myTestMethod()
    {
        sf::Transform transform;
        return transform;
    }
};

