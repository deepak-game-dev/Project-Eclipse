#include "Player.h"
#include <algorithm>

void Player::Update(float dt)
{
   
}
void Player::TakeDamage(int damage)
{
    if (damage <= 0)
        return;
    SetHealth(health - damage);
}
void Player::Heal(int amount)
{
    if (amount <= 0)
        return;

    SetHealth(health + amount);
}
void Player::SetHealth(int newHealth)
{
    health = std::clamp(newHealth, 0, MaxHealth);
}

int Player::GetHealth() const
{   
    return health;
}

bool Player::IsAlive() const
{
    return health > 0;
}
void Player::SetPosition(const Vector3& newPosition)
{
	position = newPosition;
}
Vector3 Player::GetPosition() const
{
	return position;
}