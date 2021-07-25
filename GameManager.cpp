#pragma once
#include "GameManager.h"
#include "TimeKeeper.h"
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
    this->gameObjects.push_back(&TimeKeeper::getInstance());
    this->gameObjects.push_back(&FPSMonitor::getInstance()); 
    this->gameObjects.push_back(new Player());

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
    for (auto& go : this->gameObjects)
    {
        go->update(TimeKeeper::getInstance().getDeltaTime());
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
