#include "FPSMonitor.h"
#include "GameManager.h"

void FPSMonitor::start()
{
    
}

/// <summary>
/// -
/// </summary>
/// <param name="clock"></param>
void FPSMonitor::update(sf::Time& deltaTime)
{
    //std::cout << "dt: " << deltaTime.asSeconds() << std::endl;
    float fps = 1.0f / (deltaTime.asSeconds());
    this->fpsText->setString(std::to_string(floor(fps)));
}

/// <summary>
/// -
/// </summary>
/// <param name="window">The window the FPS text is to be rendered to.</param>
void FPSMonitor::render(sf::RenderWindow& window)
{
    this->fpsText->setOrigin(50.0f - window.getSize().x, 0.0f);
    window.draw(*this->fpsText);
}
