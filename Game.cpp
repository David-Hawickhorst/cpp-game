////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#include "Game.h"

/// @brief default if no config specified
Game::Game() { init(); }

/// @brief Setup based on config params
/// @param config config file to read from
Game::Game(const std::string& config) { init(config); }
