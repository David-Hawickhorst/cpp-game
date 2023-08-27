////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#pragma once
#include "Entity.h"
#include "EntityManager.h"
#include "Systems.h"

#include <memory>
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    Game(const std::string& config);
    void run();

private:
    sf::RenderWindow m_window;
    EntityManager m_entityManager;
    sf::Font m_font;
    sf::Text m_text;
    // TODO: implement configs
    //    PlayerConfig m_playerConfig;
    //    EnemyConfig m_enemyConfig;
    //    BulletConfig m_bulletConfig;
    int m_score              = 0;
    int m_currentFrame       = 0;
    int m_lastEnemySpawnTime = 0;
    bool m_paused            = false;
    bool m_running           = true;

    std::shared_ptr<Entity> m_player;

    void init();
    void init(const std::string& path);
    void setPaused(bool paused) { m_paused = paused; };

    void spawnPlayer();
    void spawnEnemy();
    void spawnBullet(std::shared_ptr<Entity> entity, const Vec2& mousePos);
};
