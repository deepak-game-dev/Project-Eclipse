#include "Game.h"

Game::Game()
{
    player = entityManager.CreatePlayer();

    enemy.SetPosition(Vector3(5.0f, 0.0f, 5.0f));
}

void Game::Update(float dt)
{
    if (player == nullptr || playerCaptured || playerEscaped)
        return;

  
    inputSystem.Update();

    Vector3 direction = inputSystem.GetMovementInput();
    Vector3 position = player->GetPosition();

    movementSystem.Move(position, direction, dt);
    player->SetPosition(position);

    cameraSystem.Update(player->GetPosition());

  
    Vector3 playerPosition = player->GetPosition();
    enemy.DetectPlayer(playerPosition);


    if (enemy.IsAlive() && enemy.IsPlayerDetected())
    {
        Vector3 enemyPosition = enemy.GetPosition();

        Vector3 directionToPlayer =
            playerPosition - enemyPosition;

        Vector3 normalizedDirection =
            directionToPlayer.Normalized();

        enemyPosition = enemyPosition +
            (normalizedDirection * enemySpeed * dt);

        enemy.SetPosition(enemyPosition);
    }

    Vector3 enemyPosition = enemy.GetPosition();
    float distanceToEnemy =
        (playerPosition - enemyPosition).Magnitude();

    if (distanceToEnemy <= captureRange)
    {
        playerCaptured = true;
        return;
    }


    float distanceToExit =
        (playerPosition - exitPosition).Magnitude();

    if (distanceToExit <= escapeRange)
    {
        playerEscaped = true;
    }
}

Vector3 Game::GetPlayerPosition() const
{
    if (player == nullptr)
        return Vector3(0.0f, 0.0f, 0.0f);

    return player->GetPosition();
}

bool Game::IsEnemyDetectingPlayer() const
{
    return enemy.IsPlayerDetected();
}
Vector3 Game::GetEnemyPosition() const
{
    return enemy.GetPosition();
}
bool Game::IsPlayerCaptured() const
{
    return playerCaptured;
}

bool Game::IsPlayerEscaped() const
{
    return playerEscaped;
}
