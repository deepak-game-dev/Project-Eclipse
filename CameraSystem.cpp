#include "CameraSystem.h"

CameraSystem::CameraSystem()
    : cameraPosition(0.0f, 0.0f, 0.0f),
    offset(0.0f, 3.0f, -5.0f)
{
}

void CameraSystem::Update(const Vector3& targetPosition)
{
    cameraPosition = targetPosition + offset;
}

Vector3 CameraSystem::GetCameraPosition() const
{
    return cameraPosition;
}