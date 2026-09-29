#include "Vector3.h"
#include <cmath>
Vector3::Vector3(float X, float Y, float Z) : X(X), Y(Y), Z(Z)
{

}

Vector3 Vector3 ::operator+(const Vector3& other) const
{
	return Vector3(X + other.X, Y + other.Y, Z + other.Z);
}
Vector3 Vector3 ::operator-(const Vector3& other) const
{
	return Vector3(X - other.X, Y - other.Y, Z - other.Z);
}
float Vector3::operator*(const Vector3& other) const
{
	return (X * other.X) +
		(Y * other.Y) +
		(Z * other.Z);
}
Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(X * scalar, Y * scalar, Z * scalar);
}
float Vector3::Magnitude() const
{
	return std::sqrt(X * X + Y * Y + Z * Z);
}
Vector3 Vector3::Normalized() const
{

	float magnitude = Magnitude();
	if (magnitude == 0.0f)
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}
	else
	{
		return Vector3(X / magnitude, Y / magnitude, Z / magnitude);
	}
	
	
}