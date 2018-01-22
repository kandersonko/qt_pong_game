#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include "paddle.h"
#include "ball.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // create a game scene
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, width(), height());

    // add game objects
    Paddle *player = new Paddle();
    player->setPos(5, (height() / 2.0) - player->height());
    player->setBrush(Qt::blue);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    Paddle *computer = new Paddle();
    computer->setPos(width() - computer->width() - 5, (height() / 2) - computer->height());

    Ball *ball = new Ball();
    ball->setPaddles(player, computer);
    ball->setPos(player->x() + ball->width() + 12, player->y() + player->height() / 2);

    scene->addItem(player);
    scene->addItem(computer);
    scene->addItem(ball);


    // create a game view
    ui->gameView->setScene(scene);
    ui->gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->gameView->setGeometry(0, 0, width(), height());
    ui->gameView->setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "This is an alpha version of a simple pong game built with Qt.", "OK");
}

void MainWindow::on_actionHow_to_play_triggered()
{
    QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setWindowTitle("How to play");
    msgBox->setText("Use arrow keys UP and Down to move the paddle in order to hit the ball");
    msgBox->setInformativeText("You win when the ball passes the computer paddle.\nHowever score in not implemented yet");
    msgBox->exec();
}
