////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#pragma once
#include "Entity.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

using EntityVec = std::vector<std::shared_ptr<Entity>>;
using EntityMap = std::map<std::string, EntityVec>;

class EntityManager {
public:
    EntityManager();
    void update();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    const EntityVec& getEntities(const std::string& tag);
    const EntityVec& getEntities() { return m_entities; }

private:
    EntityVec m_entities;
    EntityVec m_toAdd;
    EntityMap m_entityMap;
    size_t m_totalEntities;
};
