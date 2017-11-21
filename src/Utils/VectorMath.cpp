#include "VectorMath.h"
#include <math.h>

Vector2 normalize(const Vector2& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return Vector2(source.x / length, source.y / length);
	else
		return source;
}

float dot(const Vector2& vec1, const Vector2& vec2)
{

	float	x1 = vec1.x,
			x2 = vec2.x,
			y1 = vec1.y,
			y2 = vec2.y,
			dotProduct;

	dotProduct = (x1 * x2 + y1 * y2);
	return dotProduct;
}

Vector2 proj(const Vector2& onto, const Vector2& from)
{
		return onto * (dot(from, onto) / getLengthSquared(onto));
}

float getLength(const Vector2& source)
{
		return sqrt((source.x * source.x) + (source.y * source.y));
}

float getLengthSquared(const Vector2& source)
{
		return (source.x * source.x) + (source.y * source.y);
}

bool circleLineCollision(Vector2 a, Vector2 b, Vector2 c, float r)
{
	Vector2 vectorToCenter = c - a;
	Vector2 ab = (b - a);
	Vector2 projectedVector = proj(normalize(b - a), vectorToCenter);
	Vector2 d = a + projectedVector;
	Vector2 dc = c - d;
	Vector2 ad = d - a;

	bool shorter = (getLengthSquared(projectedVector) < getLengthSquared(b - a));
	bool inRadius = getLengthSquared(dc) < r * r;

	bool sameDirX = (ad.x * ab.x) >= 0;
	bool sameDirY = (ad.y * ab.y) >= 0;

	bool sameSign = sameDirX && sameDirY;
	return shorter && inRadius && sameSign;

}

Vector2 findNormal(const Vector2& source)
{
	return Vector2(source.y, -source.x);
}

float lerp(float a, float b, float t)
{
    return (1 -t) * a + t * b;
}

Vector2 lerp(const Vector2& a, const Vector2& b, float t)
{
    Vector2 vec;
    vec.x = lerp(a.x, b.x, t);
    vec.y = lerp(a.y, b.y, t);

    return vec;
}


