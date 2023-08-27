////////////////////////////////////////////////////////
/// @brief
////////////////////////////////////////////////////////

#include "Vec2.h"

///////////////////////////////////////////////////////////////////////////////
// Comparison Operators
///////////////////////////////////////////////////////////////////////////////
bool Vec2::operator==(const Vec2& rhs) const { return x == rhs.x && y == rhs.y; }
bool Vec2::operator!=(const Vec2& rhs) const { return !(rhs == *this); }

///////////////////////////////////////////////////////////////////////////////
// Operators returning new Vec2 object
///////////////////////////////////////////////////////////////////////////////
Vec2 Vec2::operator+(const Vec2& rhs) const { return {x + rhs.x, y + rhs.y}; }
Vec2 Vec2::operator-(const Vec2& rhs) const { return {x - rhs.x, y - rhs.y}; }
Vec2 Vec2::operator/(const float val) const { return {x / val, y / val}; }
Vec2 Vec2::operator*(const float val) const { return {x * val, y * val}; }

///////////////////////////////////////////////////////////////////////////////
// Operators modifying the Calling Vec2 object
///////////////////////////////////////////////////////////////////////////////
void Vec2::operator+=(const Vec2& rhs) {
    x += rhs.x;
    y += rhs.y;
}
void Vec2::operator-=(const Vec2& rhs) {
    x -= rhs.x;
    y -= rhs.y;
}
void Vec2::operator*=(const float val) {
    x *= val;
    y *= val;
}
void Vec2::operator/=(const float val) {
    x /= val;
    y /= val;
}
///////////////////////////////////////////////////////////////////////////////
// Methods returning reference to object, allowing for method chaining
///////////////////////////////////////////////////////////////////////////////
Vec2& Vec2::add(const Vec2& v) {
    x += v.x;
    y += v.y;
    return *this;
}
Vec2& Vec2::scale(const float val) {
    x *= val;
    y *= val;
    return *this;
}
Vec2& Vec2::rotate(const float deg) {
    float rads = deg * M_PI / 180.0f;

    float cosAngle = std::cos(rads);
    float sinAngle = std::sin(rads);

    x = x * cosAngle - y * sinAngle;
    y = x * sinAngle + y * cosAngle;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Normal class methods
///////////////////////////////////////////////////////////////////////////////

/**
 * @brief Computes distance from caller to input vector. Does sqrt( (input.x - caller.x)^2 + (input.y - caller.y)^2 )
 * @param vec Vector to calculate the distance to
 * @return Distance from caller to the input vector
 */
float Vec2::distanceTo(const Vec2& vec) const { return sqrtf((vec.x - x) * (vec.x - x) + (vec.y - y) * (vec.y - y)); }

/**
 * @brief gets the magnitude of the vector. sqrt(x^2 + y^2)
 * @return magnitude of vector
 */
float Vec2::magnitude() const {
    const float length = sqrtf(x * x + y * y);
    return length;
}

/**
 * @brief Normalzies the vector. Preserves angle, but sets magnitude to be within 1
 * @return A new normalized vector
 */
Vec2 Vec2::normalize() const {
    float len = magnitude();
    return {x / len, y / len};
}
