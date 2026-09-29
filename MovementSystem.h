#pragma once
#include "InputSystem.h"

class MovementSystem
{
private:
	float MoveSpeed = 5.0f;
public:
	void Move(Vector3& position, const Vector3& direction, float dt);
};