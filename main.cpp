#include "assets/environment/environment.h"
#include "assets/widgets/boardsetup.h"
#include "assets/widgets/gamewidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    int x {10};
    int y{10};
    Player p;
    Environment e{x,y,&p};
    QApplication a(argc, argv);
    GameWidget g{nullptr,&e};
    BoardSetup b{nullptr,&g};
    b.show();
    return QApplication::exec();
}
