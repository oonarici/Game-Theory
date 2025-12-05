//
// Created by Onur Onarıcı on 4.12.2025.
//

#ifndef PERSON_H
#define PERSON_H

#include <random>

int randomMinusOneZeroOne()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dist(0, 2);

    return dist(gen);
}

class Player {
private:
    std::int8_t m_move {};
    bool m_didLose {};

public:
    std::int8_t getChooise() const;
    void setDidLoose(bool result);
    virtual std::int8_t move();
};


inline std::int8_t Player::getChooise() const
{
    return m_move;
}


inline void Player::setDidLoose(bool result)
{
    m_didLose = result;
}

inline std::int8_t Player::move()
{
    m_move = randomMinusOneZeroOne();
    return m_move;
}
#endif //PERSON_H
