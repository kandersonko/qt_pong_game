#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMessageBox *msgBox = new QMessageBox(&w);
    msgBox->setWindowTitle("How to play");
    msgBox->setText("Use arrow keys UP and Down to move the paddle in order to hit the ball");
    msgBox->setInformativeText("You win when the ball passes the computer paddle.\nHowever score in not implemented yet");
    msgBox->setStandardButtons(QMessageBox::Ok);
    msgBox->setModal(true);
    w.setFixedSize(BOARD_WIDTH, BOARD_HEIGHT);
    w.show();

    return a.exec();
}
