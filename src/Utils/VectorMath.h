#ifndef VECTORMATH
#define VECTORMATH

#include <SFML/Graphics.hpp>

typedef sf::Vector2f Vector2;

Vector2 normalize(const Vector2& source);
float dot(const Vector2& vec1, const Vector2& vec2);
Vector2 proj(const Vector2& onto, const Vector2& from);
float getLength(const Vector2& source);
float getLengthSquared(const Vector2& source);
bool circleLineCollision(Vector2 a, Vector2 b, Vector2 c, float r);
Vector2 findNormal(const Vector2& source);
float lerp(float a, float b, float t);
Vector2 Lerp(const Vector2& a, const Vector2& b, float t);

#endif