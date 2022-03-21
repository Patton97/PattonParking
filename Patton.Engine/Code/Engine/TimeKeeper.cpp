#include "TimeKeeper.h"

/// <summary>
/// 
/// </summary>
void TimeKeeper::start()
{
    this->clock = sf::Clock::Clock();
}

/// <summary>
/// 
/// </summary>
/// <param name="deltaTime"></param>
void TimeKeeper::update(sf::Time& deltaTime)
{
    this->currentTime = clock.getElapsedTime();
    this->deltaTime = this->currentTime - this->previousTime;
    this->previousTime = currentTime;
}

/// <summary>
/// 
/// </summary>
/// <param name="window"></param>
void TimeKeeper::render(sf::RenderWindow& window)
{
    // we don't want to render anything for this
    // NOTE: could we improve this by asking the game manager to handle updateables & renderables separately?
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
sf::Time& TimeKeeper::getDeltaTime()
{
    return this->deltaTime;
}
