#include "gamecontroller.h"

GameController::GameController()
{
    m_speed = 10;
}

void GameController::move(Paddle *computer)
{
    qreal dy = -(rand() % 2) + 1;
    computer->setPos(computer->x(), computer->y() + (GameController::m_speed * dy));
}
