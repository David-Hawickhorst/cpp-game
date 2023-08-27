/******************************************************************************
 * @brief
 *****************************************************************************/
#pragma once

#include "Entity.h"
#include "Vec2.h"

// Systems to control components such as movement() will operate on CTransform
void sMovement();
void sUserInput();
void sLifespan();
void sRender();
void sEnemySpawner();
void sCollision();
