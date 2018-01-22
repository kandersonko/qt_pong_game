#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "paddle.h"
#include "ball.h"


class GameController
{
public:
    GameController();
    void move(Paddle *computer);

protected:
    qreal m_speed;
};

#endif // GAMECONTROLLER_H
