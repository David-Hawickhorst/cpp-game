////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#include "Game.h"

/// @brief default if no config specified
Game::Game() { init(); }

/// @brief Setup based on config params
/// @param config config file to read from
Game::Game(const std::string& config) { init(config); }


/**
 * @brief default configuration if none given
 */
void Game::init() {
    m_window.create(sf::VideoMode(1280, 720), "Window Name");
    m_window.setFramerateLimit(60);
    spawnPlayer();
}

void Game::init(const std::string& path) {}

void Game::spawnPlayer() {}
