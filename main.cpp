#include "mainwindow.h"
#include <QApplication>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(BOARD_WIDTH, BOARD_HEIGHT);
    w.show();

    return a.exec();
}
