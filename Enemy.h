#pragma once

#include "Entity.h"
#include "Vector3.h"

class Enemy : public Entity
{
private:
    int health = 100;
    int maxHealth = 100;

    Vector3 position{ 0.0f, 0.0f, 0.0f };

    float detectionRange = 10.0f;
    bool playerDetected = false;

public:
    void Update(float dt) override;
    bool IsAlive() const override;

    void SetHealth(int newHealth);
    int GetHealth() const;
    void TakeDamage(int damage);

    void SetPosition(const Vector3& newPosition);
    Vector3 GetPosition() const;

    void DetectPlayer(const Vector3& playerPosition);
    bool IsPlayerDetected() const;
};