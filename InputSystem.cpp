#include "InputSystem.h"
#include <conio.h>
InputSystem::InputSystem() : MovementInput(0.0f, 0.0f, 0.0f)
{
}

void InputSystem::Update()
{
	MovementInput = Vector3(0.0f, 0.0f, 0.0f);
    while (_kbhit())
    {
        char key = _getch();

        switch (key)
        {
        case 'w':
        case 'W':
            MovementInput.Z += 1.0f;
            break;

        case 's':
        case 'S':
            MovementInput.Z -= 1.0f;
            break;

        case 'a':
        case 'A':
            MovementInput.X -= 1.0f;
            break;

        case 'd':
        case 'D':
            MovementInput.X += 1.0f;
            break;
        }
    }
}

Vector3 InputSystem::GetMovementInput() const
{
	return MovementInput;
}