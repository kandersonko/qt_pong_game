#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include "paddle.h"

class Ball: public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT

    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(int speed READ speed)

public:
    Ball();
    void setPaddles(Paddle *player, Paddle *computer);
    bool insideBoard();
//    QRectF boundingRect() const override;
    int width();
    int height();
    int speed();

public slots:
    void move();


private:
    Paddle *m_player;
    Paddle *m_computer;
    int m_width = 10;
    int m_height = 10;
    qreal dx, dy, m_speed;
};

#endif // BALL_H
