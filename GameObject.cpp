#include "GameObject.h"

void GameObject::update(sf::Time& deltaTime)
{
    for (auto& component : this->m_components)
    {
        component->update(deltaTime);
    }
    for (auto& child : this->m_children)
    {
        child->update(deltaTime);
    }
}

void GameObject::render(sf::RenderWindow& window)
{
    for (auto& child : this->m_children)
    {
        child->render(window);
    }
}

void GameObject::renderGizmos(sf::RenderWindow& window)
{
    for (auto& child : this->m_children)
    {
        child->renderGizmos(window);
    }
}

void GameObject::setParent(GameObject* parent)
{
    // clear existing parent (if present)
    if (this->m_parent != nullptr)
    {
        parent->removeChild(*this);
    }
    // tell new parent to add [this] as a child
    parent->addChild(*this);
}

void GameObject::addChild(GameObject& child)
{
    child.m_parent = this;
    this->m_children.push_back(&child);
}

void GameObject::removeChild(GameObject& child)
{
    this->m_children.erase(std::remove(this->m_children.begin(), this->m_children.end(), &child), this->m_children.end());
    child.m_parent = nullptr;
}
