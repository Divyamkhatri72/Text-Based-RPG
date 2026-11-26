#include "assets/environment/environment.h"
#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    int x {10};
    int y{10};
    Environment e{x,y};
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
