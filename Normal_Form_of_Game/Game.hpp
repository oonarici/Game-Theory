//
// Created by Onur Onarıcı on 4.12.2025.
//

#ifndef GAME_H
#define GAME_H

#include "Player.hpp"
#include <array>
/*
 *        Rock Paper Scisor
 * Rock    00   10    01
 * Paper   01   00    10
 * Scisor  10   01    00
 */

namespace RPS
{
    static constexpr std::array<std::array<std::int8_t, 3>, 3> table = {{
        {{  0,   -1,    1 }},
        {{  1,    0,   -1 }},
        {{ -1,    1,    0 }}
    }};

    class Game
    {
    public:
        std::int8_t get_result(RPS::Player& player1,
                               RPS::Player& player2)
        {
            std::int8_t result{table[player1.move()][player2.move()]};
            if (result == 0)
            {
                player1.setDidLose(false);
                player2.setDidLose(false);
                return 0;
            }
            else if (result == -1)
            {
                player1.setDidLose(true);
                player2.setDidLose(false);
                return -1;
            }
            else
            {
                player1.setDidLose(false);
                player2.setDidLose(true);
                return 1;
            }
        }
    };
}

#endif //GAME_H
