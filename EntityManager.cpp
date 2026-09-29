#include "EntityManager.h"
#include "Player.h"
#include <algorithm>

void EntityManager::AddEntity(std::unique_ptr<Entity> entity)
{
    if (entity)
    {
        entities.push_back(std::move(entity));
    }
}
Player* EntityManager::CreatePlayer()
{
    auto player = std::make_unique<Player>();
    Player* playerPtr = player.get();

    entities.push_back(std::move(player));

    return playerPtr;
}void EntityManager::UpdateAll(float dt)
{
    for (const auto& entity : entities)
    {
        entity->Update(dt);
    }
}
void EntityManager::RemoveInactive()
{
    entities.erase(
        std::remove_if(
            entities.begin(),
            entities.end(),
            [](const std::unique_ptr<Entity>& entity)
            {
                return !entity->IsAlive();
            }),
        entities.end());
}

Player* EntityManager::GetPlayer()
{
    for (const auto& entity : entities)
    {
        Player* player = dynamic_cast<Player*>(entity.get());

        if (player != nullptr)
            return player;
    }

    return nullptr;
}