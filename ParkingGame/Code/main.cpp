#include <iostream>
#include "GameManager.h"

int main()
{
    GameManager gameManager;

    // game manager loop
    while (gameManager.isWindowOpen())
    {
        gameManager.eventUpdate();
        gameManager.update();
        gameManager.render();
    }

    return 0;
}