#pragma once
#include "Vector3.h"

class CameraSystem
{
private:
    Vector3 cameraPosition;
    Vector3 offset;

public:
    CameraSystem();

    void Update(const Vector3& targetPosition);
    Vector3 GetCameraPosition() const;
};