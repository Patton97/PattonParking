#include "GameObject.h"
#include <assert.h> 

void GameObject::update(sf::Time& deltaTime)
{
    /*for (auto& component : this->m_components)
    {
        component->update(deltaTime);
    }*/
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

void GameObject::addComponent(GameComponent& componentToAdd)
{
    //this->m_components.push_back(&componentToAdd);

    const char* componentTypeName = typeid(componentToAdd).name();
    std::map<std::string, std::vector<GameComponent*>>::iterator it = this->m_componentsMap.find(componentTypeName);
    std::vector<GameComponent*> componentVector;
    if (it != this->m_componentsMap.end())
    {
        componentVector = it->second;
    }
    else
    {
        componentVector = {};
    }
    componentVector.push_back(&componentToAdd);
}

void GameObject::removeComponent(GameComponent& componentToRemove)
{
    //this->m_components.push_back(&componentToAdd);

    const char* componentTypeName = typeid(componentToRemove).name();
    std::map<std::string, std::vector<GameComponent*>>::iterator it = this->m_componentsMap.find(componentTypeName);

    if (it == this->m_componentsMap.end())
    {
        return;
    }

    std::vector<GameComponent*> componentVector = it->second;
    if (componentVector.empty())
    {
        return;
    }

    int indexToRemove = -1;
    for (int i = 0; i < componentVector.size(); ++i)
    {
        if (componentVector[i] == &componentToRemove)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1)
    {
        return;
    }

    this->removeComponent(componentVector, indexToRemove);
}

void GameObject::removeComponent(std::vector<GameComponent*>& componentVector, int indexToRemove)
{
    componentVector.erase(std::next(componentVector.begin(), indexToRemove));
}

template<class T>
std::vector<T*> GameObject::getComponents()
{
    //assert(std::is_base_of<GameComponent, T>);
    const char* componentTypeName = typeid(T).name();
    std::map<std::string, std::vector<GameComponent*>>::iterator it = this->m_componentsMap.find(componentTypeName);

    if (it == this->m_componentsMap.end())
    {
        return;
    }

    return it->second;
}

template<class T>
T& GameObject::getComponent()
{
    return this->getComponents<T>()[0];
}