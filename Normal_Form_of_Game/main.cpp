#include <iostream>
#include "Game.hpp"

int main() {

    RPS::RandomStrategyPlayer player1;
    RPS::CycleStrategyPlayer player2;
    RPS::AlwaysPaperStrategyPlayer player3;
    RPS::WinStayLoseSwitchPlayer player4;

    RPS::Game game;
    int total {0};
    for (int i = 0; i < 1000; i++)
    {
        int one_game {};
        for (int j = 0; j < 3; j++)
        {
            one_game += game.get_result(player4, player3);
        }
        if (one_game > 0) {
            total++;
        }
        else if (one_game < 0) {
            total--;
        }
        else {
            continue;
        }
    }
    std::cout << total << std::endl;
    return 0;
}