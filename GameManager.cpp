#pragma once
#include "GameManager.h"
#include "FPSMonitor.h"
#include "Player.h"

GameManager::GameManager()
{
    this->initWindow();
    this->start();
}

GameManager::~GameManager()
{
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
    this->clock = sf::Clock::Clock();
    Player* player = new Player();
    this->gameObjects.push_back(player);
    this->gameObjects.push_back(&FPSMonitor::getInstance());
    
    for (auto& go : this->gameObjects)
    {
        go->start();
    }
}

void GameManager::eventUpdate()
{
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
    }

    for (auto& go : this->gameObjects)
    {
        go->eventUpdate(ev);
    }
}

void GameManager::update()
{
    this->updateDeltaTime();
    for (auto& go : this->gameObjects)
    {
        go->update(this->deltaTime);
    }
}

void GameManager::render()
{
    this->window->clear(sf::Color::Black);
    
    for (auto& go : this->gameObjects)
    {
        go->render(*this->window);
    }

    this->window->display();
}

void GameManager::updateDeltaTime()
{
    this->currentTime = clock.getElapsedTime();
    this->deltaTime = this->currentTime - this->previousTime;
    this->previousTime = currentTime;
}
