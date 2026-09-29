#include "MovementSystem.h"

void MovementSystem::Move(Vector3& position, const Vector3& direction, float dt)
{
	Vector3 normalizedDirection = direction.Normalized();
	position = position + (normalizedDirection * MoveSpeed * dt);	
}