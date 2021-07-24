#pragma once
#include "GameManager.h"

#include "Player.h"

GameManager::GameManager()
{
    this->initWindow();
    this->start();
}

GameManager::~GameManager()
{
    delete this->window;
    delete this->videoMode;
}

const bool GameManager::isWindowOpen() const
{
    return this->window->isOpen();
}

void GameManager::initWindow()
{
    this->videoMode = new sf::VideoMode(640, 480);
    this->windowTitle = "Patton Parking";
    this->window = new sf::RenderWindow(*videoMode, windowTitle, sf::Style::Titlebar | sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
}

void GameManager::start()
{
    this->deltaClock = sf::Clock::Clock();
    this->clock = sf::Clock::Clock();
    this->previousTime = this->clock.getElapsedTime();
    this->window = nullptr;
    this->player = new Player();

    if (!this->fpsTextFont->loadFromFile(".\\assets\\fonts\\cour.ttf"))
    {
        std::cout << "Font failed to load" << std::endl;
    }
    fpsText->setFillColor(sf::Color::Red);
    fpsText->setFont(*fpsTextFont);

    initWindow();
}

void GameManager::eventUpdate()
{
    sf::Time deltaTime = this->deltaClock.restart();
    // while we're receiving events from the window, store them into ev
    while (this->window->pollEvent(ev))
    {
        switch (ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            default:
                break;
        }

        //this->player->m_controller->eventUpdate(ev);
    }
}

void GameManager::update()
{
    this->deltaClock.restart();
    this->updateFPS();
    this->player->update(*this->window, ev, this->deltaClock);
}

void GameManager::render()
{
    this->window->clear(sf::Color::Black);
    this->window->draw(*fpsText);

    this->player->render(*this->window);

    this->window->display();
}

void GameManager::updateFPS()
{
    float fps;
    this->currentTime = this->clock.getElapsedTime();

    fps = 1.0f / (this->currentTime.asSeconds() - this->previousTime.asSeconds());
    this->previousTime = currentTime;

    this->fpsText->setOrigin(50.0f - (*this->window).getSize().x, 0.0f);
    this->fpsText->setString(std::to_string(floor(fps)));
}
