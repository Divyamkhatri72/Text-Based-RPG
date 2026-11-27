#include "assets/environment/environment.h"
#include "assets/widgets/boardsetup.h"
#include "assets/widgets/characterselect.h"
#include "assets/widgets/gamewidget.h"
#include <QApplication>
#include <ctime>


int main(int argc, char *argv[])
{
    Player p;
    Environment e{3,3,&p};
    QApplication a(argc, argv);

    GameWidget g{nullptr,&e};
    CharacterSelect c{nullptr,&g,&p};
    BoardSetup b{nullptr,&c,&e};

    b.show();
    return QApplication::exec();
}
