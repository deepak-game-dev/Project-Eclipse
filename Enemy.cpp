#include "Enemy.h"
#include <algorithm>

void Enemy::Update(float dt)
{
}

bool Enemy::IsAlive() const
{
    return health > 0;
}

void Enemy::SetHealth(int newHealth)
{
    health = std::clamp(newHealth, 0, maxHealth);
}

int Enemy::GetHealth() const
{
    return health;
}

void Enemy::TakeDamage(int damage)
{
    if (damage <= 0)
        return;

    SetHealth(health - damage);
}

void Enemy::SetPosition(const Vector3& newPosition)
{
    position = newPosition;
}

Vector3 Enemy::GetPosition() const
{
    return position;
}

void Enemy::DetectPlayer(const Vector3& playerPosition)
{
    if (!IsAlive())
    {
        playerDetected = false;
        return;
    }

    float distance = (position - playerPosition).Magnitude();
    playerDetected = (distance <= detectionRange);
}

bool Enemy::IsPlayerDetected() const
{
    return playerDetected;
}