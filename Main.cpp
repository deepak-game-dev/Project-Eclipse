#include "Game.h"
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    Game game;

    std::cout << "PROJECT ECLIPSE\n";
    std::cout << "Escape the enemy and reach the exit!\n";
    std::cout << "Controls: W A S D\n\n";

    while (true)
    {
        game.Update(0.1f);

        if (game.IsPlayerCaptured())
        {
            std::cout << "\n\nGAME OVER! The enemy caught you.\n";
            break;
        }

        if (game.IsPlayerEscaped())
        {
            std::cout << "\n\nYOU ESCAPED! Mission complete.\n";
            break;
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(100));
    }

    return 0;
}


