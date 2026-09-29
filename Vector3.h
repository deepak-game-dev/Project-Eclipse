#pragma once
class Vector3
{
public:
	float X;
	float Y;
	float Z;

	Vector3(float X, float Y, float Z);
	float Magnitude() const;
	Vector3 Normalized() const;
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator-(const Vector3& other) const;
	float operator*(const Vector3& other) const;
	Vector3 operator*(float scalar) const;
	
	
};