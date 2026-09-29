#pragma once
#include "Entity.h"
#include <vector>
#include <memory>

class Player;
class EntityManager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void AddEntity(std::unique_ptr<Entity> entity);
    void UpdateAll(float dt);
    void RemoveInactive();
    Player* GetPlayer();
    Player* CreatePlayer();
};