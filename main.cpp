#include "assets/environment/environment.h"
#include "boardsetup.h"
#include "gamewidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    int x {10};
    int y{10};
    Environment e{x,y};
    QApplication a(argc, argv);
    GameWidget g;
    BoardSetup b{nullptr,&g};
    b.show();
    return QApplication::exec();
}
