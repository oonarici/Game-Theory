#include <iostream>
#include "Game.hpp"

int main() {

    Player player1;
    Player player2;

    Game game;
    int total {};
    for (int i = 0; i < 100; i++)
    {
        total += game.get_result(player1, player2);
    }

    std::cout << total << std::endl;
    return 0;
}