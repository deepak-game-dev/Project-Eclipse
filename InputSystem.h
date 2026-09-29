#pragma once
#include "Vector3.h"

class InputSystem
{
private:
	Vector3 MovementInput;
public:
	InputSystem();
	void Update();
	Vector3 GetMovementInput() const;
};
