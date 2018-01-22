#ifndef PADDLE_H
#define PADDLE_H
#include "config.h"

#include<QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>


class Paddle: public QObject, public QGraphicsRectItem
{
    Q_OBJECT

    Q_PROPERTY(int height READ height)
    Q_PROPERTY(int width READ width)
public:
    Paddle();
    void keyReleaseEvent(QKeyEvent *event);
    enum MoveType {UP, DOWN};
    Q_ENUM(MoveType)
    bool validMove(MoveType moveType);
    void move(MoveType moveType);
    void randomMove(qreal ballY);
    int height();
    int width();

protected:
    int m_height = 100;
    int m_width = 20;
    int m_moveStep = 15;
};

#endif // PADDLE_H
