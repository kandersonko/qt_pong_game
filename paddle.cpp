#include "paddle.h"
#include <QBrush>

Paddle::Paddle()
{
    setRect(0, 0, m_width, m_height);
    setBrush((QBrush)Qt::black);
}

void Paddle::move(Paddle::MoveType moveType)
{
    if(validMove(moveType) && moveType == UP)
        setPos(x(), y() - m_moveStep);
    else if(validMove(moveType) && moveType == DOWN)
        setPos(x(), y() + m_moveStep);
}

void Paddle::randomMove(qreal ballY)
{
    MoveType m = ((y() - ballY) > -10) ? UP : DOWN;
//    MoveType moveType = static_cast<MoveType>(-(qrand() % 2) + 1);
    move(m);
}

void Paddle::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        move(UP);
        break;
    case Qt::Key_Down:
        move(DOWN);
        break;
    default:
        break;
    }
}

bool Paddle::validMove(Paddle::MoveType moveType)
{
    if(moveType == UP) return (y() - m_moveStep) >= 0;
    else if(moveType == DOWN) return (y() + m_moveStep) <=460;
    else return false;
}

int Paddle::width()
{
    return m_width;
}

int Paddle::height()
{
    return m_height;
}
