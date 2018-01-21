#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create a game scene
    QGraphicsScene *scene = new QGraphicsScene(this);

    // add game objects
    QGraphicsRectItem *player = new QGraphicsRectItem(0, 0, 10, 80);
    player->setBrush(Qt::red);

    QGraphicsRectItem *computer = new QGraphicsRectItem(100, 0, 10, 80);
    computer->setBrush(Qt::blue);

    QGraphicsEllipseItem *ball = new QGraphicsEllipseItem(10, 10, 10, 10);
    ball->setBrush(Qt::green);

    scene->addItem(player);
    scene->addItem(computer);
    scene->addItem(ball);


    // create a game view
    ui->gameView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
