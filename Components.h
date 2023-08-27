#pragma once

#include "Vec2.h"
#include <SFML/Graphics.hpp>

/**
 * @brief for doing transforms to an entity.
 * Pos is x/y position
 * velocity is its current velocity vector
 * angle is the current rotation angle
 */
class CTransform {
public:
    Vec2 pos      = {0.0, 0.0};
    Vec2 velocity = {0.0, 0.0};
    float angle   = 0;
    CTransform()  = default;
    CTransform(const Vec2 &p, const Vec2 &v, float a) : pos(p), velocity(v), angle(a){};
};

/**
 * @brief How the Entity is displayed.
 *          radius: determine the size
 *          points: determine the shape by enclosed circle algo. Ex: 3->triangle, 4->square, etc
 *          fill: color the entity will be filled with
 *
 * @note Potential other things to add:
 *         - outline color
 *         - outline thickness
 *
 */
class CShape {
public:
    sf::CircleShape circle;
    CShape(float radius, int points, const sf::Color &fill) : circle(radius, points) {
        circle.setFillColor(fill);
        circle.setOrigin(radius, radius);
    }
};

/**
 * @brief checking for collisions
 * Will be doing collision checking by enclosed circle checks, so collisions won't be perfect
 * Ex: A Triangle and Square will detecect a collision if the circles that they're inscribed in collide
 * this means we will have collisions that don't look like it. Oh well.
 */
class CCollision {
public:
    float radius = 0;
    explicit CCollision(float r) : radius(r) {}
};

/**
 * @brief score of the entity
 * Will be used to set the player score
 * will also set an enemy score that will be used to increase the player's score
 * ex: special enemies give more score
 */
class CScore {
public:
    int score = 0;
    explicit CScore(int s) : score(s) {}
};

/**
 * @brief Lifespan of entity. Used for projectiles / effects like explosions
 */
class CLifespan {
public:
    int remaining = 0;
    int total     = 0;
    explicit CLifespan(int _total) : remaining(_total), total(_total) {}
};

/**
 * @brief user input detection. WASD/ arrow key control. Left click to shoot towards mouse pointer
 */
class CInput {
public:
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
    bool shoot = false;

    CInput() = default;
};
