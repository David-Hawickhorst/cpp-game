////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#pragma once

#include "Components.h"
#include <memory>
#include <string>


class Entity {

public:
    Entity(const std::string& tag, const size_t id) : m_tag(tag), m_id(id){};
    Entity() = default;
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CShape> cShape;
    std::shared_ptr<CCollision> cCollision;
    std::shared_ptr<CInput> cInput;
    std::shared_ptr<CScore> cScore;
    std::shared_ptr<CLifespan> cLifeSpan;

    bool isAlive() const { return m_alive; }
    const std::string& tag() const { return m_tag; }
    const size_t id() const { return m_id; }
    void destroy() { m_alive = false; }

private:
    bool m_alive      = true;
    std::string m_tag = "default";
    std::size_t m_id  = 0;
};
