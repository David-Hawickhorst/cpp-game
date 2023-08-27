/**
 * @brief My own implementation of a 2D vector class
 * SFML does have sf::Vector2f, but I'm doing this just for practice
 */

#pragma once
#include <cmath>

class Vec2 {
public:
    Vec2() = default;
    Vec2(float xin, float yin) : x(xin), y(yin){};


    // Comparision operators
    bool operator==(const Vec2& rhs) const;
    bool operator!=(const Vec2& rhs) const;

    /**
     * set of operators for operations on two vectors, that return a third one
     * Example:
     *  Vec2 v1(1,1), v2(2,2);
     *  Vec2 vec3 = v1 + v2;
     */
    Vec2 operator+(const Vec2& rhs) const;
    Vec2 operator-(const Vec2& rhs) const;
    Vec2 operator/(const float val) const;
    Vec2 operator*(const float val) const;

    /**
     * Set of operators that modify the vector.
     * Example:
     *  Vec2 v1(1, 1);
     *  Vec2 v2(2,2);
     *  v1 += v2;
     * Results in v1 = (3,3)
     */
    void operator+=(const Vec2& rhs);
    void operator-=(const Vec2& rhs);
    void operator*=(const float val);
    void operator/=(const float val);

    /**
     * set of methods that allow for method chaining by modifying the caller and returning a reference to it
     * Example:
     *  Vec2 v1(1,1);
     *  Vec2 v2(2,2);
     *  v1.add(v2).rotate(45);
     *  v1.add(v2) adds vec2 to vec1 resulting in v1=(3,3) and returning a reference to it
     *  That makes the statement become (3,3).rotate(45)
     *  So rotate(45) operates on the result of adding the vectors together. All of this modifies the vector
     */
    Vec2& add(const Vec2& v);
    Vec2& scale(const float val);
    Vec2& rotate(const float deg);

    float distanceTo(const Vec2& vec) const;
    float magnitude() const;
    Vec2 normalize() const;


private:
    float x = 0;
    float y = 0;

    // TODO: (maybe)
    void dotProduct();
    void crossProduct();
};
