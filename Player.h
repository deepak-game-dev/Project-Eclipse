#pragma once
#include "Entity.h"
#include "Vector3.h"

class Player : public Entity
{
private :
	int health = 100;	
	int MaxHealth = 100;
	Vector3 position{0.0f, 0.0f, 0.0f};

public:
	
	void Update(float dt) override;
	void TakeDamage(int damage);
	void Heal(int amount);
	void SetHealth(int health);
	int GetHealth() const;
	bool IsAlive() const override;
	void SetPosition(const Vector3& newPosition);
	Vector3 GetPosition() const;

};