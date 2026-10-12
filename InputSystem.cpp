
#include "InputSystem.h"
#include <Windows.h>

InputSystem::InputSystem()
    : MovementInput(0.0f, 0.0f, 0.0f)
{
}

void InputSystem::Update()
{
    MovementInput = Vector3(0.0f, 0.0f, 0.0f);

    if (GetAsyncKeyState('W') & 0x8000)
        MovementInput.Z += 1.0f;

    if (GetAsyncKeyState('S') & 0x8000)
        MovementInput.Z -= 1.0f;

    if (GetAsyncKeyState('A') & 0x8000)
        MovementInput.X -= 1.0f;

    if (GetAsyncKeyState('D') & 0x8000)
        MovementInput.X += 1.0f;
}

Vector3 InputSystem::GetMovementInput() const
{
    return MovementInput;
}

