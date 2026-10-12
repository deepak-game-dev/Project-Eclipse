#pragma once

#include "EntityManager.h"
#include "InputSystem.h"
#include "MovementSystem.h"
#include "Player.h"
#include "CameraSystem.h"
#include "Enemy.h"

class Game
{
private:
    EntityManager entityManager;
    Player* player = nullptr;

    Enemy enemy;

    InputSystem inputSystem;
    MovementSystem movementSystem;
    CameraSystem cameraSystem;
    bool playerCaptured = false;
    bool playerEscaped = false;
    Vector3 exitPosition{ 10.0f, 0.0f, 10.0f };

    float captureRange = 1.5f;
    float escapeRange = 4.0f;
    
    float enemySpeed = 0.2f;
public:
    Game();

    void Update(float dt);
    Vector3 GetPlayerPosition() const;
    bool IsEnemyDetectingPlayer() const;
    Vector3 GetEnemyPosition() const;
    bool IsPlayerCaptured() const;
    bool IsPlayerEscaped() const;
};