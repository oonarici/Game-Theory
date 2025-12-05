//
// Created by Onur Onarıcı on 4.12.2025.
//

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.hpp"
/*
 *        Rock Paper Scisor
 * Rock    00   10    01
 * Paper   01   00    10
 * Scisor  10   01    00
 */
static constexpr std::array<std::array<std::string, 3>, 3> table = {{{"00",  "10", "01"},
                                                       {"01",  "00", "10"},
                                                       {"01",  "10", "00"}}};
class Game {

public:
    std::int8_t get_result(Player& player1,
                           Player& player2)
    {
        std::string result{table[player1.move()][player2.move()]};
        if (result == "00")
        {
            player1.setDidLoose(false);
            player2.setDidLoose(false);
            return 0;
        }
        else if (result == "01") {
            player1.setDidLoose(true);
            player2.setDidLoose(false);
            return -1;
        }
        else {
            player1.setDidLoose(false);
            player2.setDidLoose(true);
            return 1;
        }
    }
};

#endif //GAME_H
