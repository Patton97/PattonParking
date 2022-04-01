#include "FPSMonitor.h"

void FPSMonitor::start()
{
    
}

void FPSMonitor::update(sf::Time& deltaTime)
{
    //std::cout << "dt: " << deltaTime.asSeconds() << std::endl;
    float fps = 1.0f / (deltaTime.asSeconds());
    this->fpsText->setString(std::to_string(floor(fps)));
}

void FPSMonitor::render(sf::RenderWindow& window)
{
    this->fpsText->setOrigin(50.0f - window.getSize().x, 0.0f);
    window.draw(*this->fpsText);
}
