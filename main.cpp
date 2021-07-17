#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.cpp"
#include "PlayerController.cpp"

int main()
{
    // Window set up
    sf::RenderWindow window(sf::VideoMode(640, 480), "Patton Parking", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    sf::Event ev;

    Player* player = new Player();

    sf::Clock deltaClock = sf::Clock::Clock();;


    float fps;
    sf::Clock clock = sf::Clock::Clock();
    sf::Time previousTime = clock.getElapsedTime();
    sf::Time currentTime;
    sf::Text* fpsText = new sf::Text();
    sf::Font* fpsTextFont = new sf::Font();
    if (!fpsTextFont->loadFromFile(".\\assets\\fonts\\cour.ttf"))
    {
        std::cout << "Font failed to load" << std::endl;
    }
    fpsText->setOrigin(50.0f - window.getSize().x, 0.0f);
    std::cout << fpsText->getOrigin().x << "," << fpsText->getOrigin().y << std::endl;
    fpsText->setFillColor(sf::Color::Red);
    fpsText->setFont(*fpsTextFont);

    // Window loop
    while (window.isOpen())
    {
        sf::Time deltaTime = deltaClock.restart();
        player->m_controller->PreEventUpdate();
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

            player->m_controller->EventUpdate(ev);
        }

        currentTime = clock.getElapsedTime();
        fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
        //std::cout << "fps =" << floor(fps) << std::endl; // flooring it will make the frame rate a rounded number
        //std::cout << fpsText->getString().toAnsiString() << std::endl; // flooring it will make the frame rate a rounded number
        previousTime = currentTime;
        
        fpsText->setString(std::to_string(floor(fps)));
        

        // Render
        window.clear(sf::Color::Black);
        window.draw(*fpsText);
        player->update(window, ev, deltaClock);

        window.display();
    }

    return 0;
}