//
// Created by Onur Onarıcı on 4.12.2025.
//

#ifndef PERSON_H
#define PERSON_H

#include <random>
#include <iostream>

namespace RPS {
    inline std::int8_t randomMoveZeroOneTwo()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<int> dist(0, 2);

        return static_cast<int8_t>(dist(gen));
    }

    class Player
    {

    protected:
        std::int8_t m_move {};
        bool m_didLose {false};

    public:
        virtual std::int8_t move() = 0;
        void setDidLose(bool didLose)
        {
            m_didLose = didLose;
        }
    };

    class RandomStrategyPlayer: public Player
    {
    public:
        inline std::int8_t move() override
        {
            return randomMoveZeroOneTwo();
        }
    };

    class CycleStrategyPlayer: public Player
    {
    private:
        std::int8_t m_current {0};

    public:
        std::int8_t move() override
        {
            std::int8_t result = m_current;
            m_current = (m_current + 1) % 3;
            return result;
        }
    };

    class AlwaysRockStrategyPlayer: public Player
    {
    public:
        std::int8_t move() override
        {
            return 0;
        }
    };

    class AlwaysPaperStrategyPlayer: public Player
    {
    public:
        std::int8_t move() override
        {
            return 1;
        }
    };

    class AlwaysScisorStrategyPlayer: public Player
    {
    public:
        std::int8_t move() override
        {
            return 2;
        }
    };

    class BiasedRandomPlayer : public Player
    {
    private:
        std::mt19937 gen{std::random_device{}()};
        std::uniform_real_distribution<double> dist{0.0, 1.0};

    public:
        std::int8_t move() override
        {
            double r = dist(gen);
            if (r < 0.5)
            {
                return 0; // Rock
            }
            else if (r < 0.75)
            {
                return 1; // Paper
            }
            else
            {
                return 2; // Scissor
            }
        }
    };

    class WinStayLoseSwitchPlayer : public Player
    {
    private:
        bool m_firstMove{true};

    protected:
        std::int8_t move() override
        {
            if (m_firstMove)
            {
                m_move = randomMoveZeroOneTwo();
                m_firstMove = false;
                return m_move;
            }
            if (m_didLose)
            {
                m_move++;
                return m_move;
            }
            else
            {
                return m_move;
            }
        }
    };
};

#endif //PERSON_H
