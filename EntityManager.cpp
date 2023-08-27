////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#include "EntityManager.h"
EntityManager::EntityManager() = default;

void EntityManager::update() {
    for (auto& e : m_toAdd) {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag) {
    auto e = std::make_shared<Entity>(tag, m_totalEntities++);
}
