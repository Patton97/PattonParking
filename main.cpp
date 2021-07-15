#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main()
{
    // Window set up
    sf::RenderWindow window(sf::VideoMode(640, 480), "Patton Parking", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;
    sf::CircleShape circle(100.0f);
    sf::Clock deltaClock;
    sf::Vector2f* movementVector = new sf::Vector2f(1.0f, 1.0f);
    const float MOVE_SPEED = 100.0f;

    // Window loop
    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();
        movementVector->x = movementVector->y = 0;

        // while we're receiving events from the window, store them into ev
        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        
        circle.move(*movementVector * deltaTime.asSeconds());

        // Render
        window.clear(sf::Color::Magenta);

        window.draw(circle);

        window.display();
    }

    return 0;
}