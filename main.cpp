#include "assets/environment/environment.h"
#include "assets/widgets/boardsetup.h"
#include "assets/widgets/characterselect.h"
#include "assets/widgets/gamewidget.h"
#include <QApplication>
#include <ctime>
#include <memory>



int main(int argc, char *argv[])
{
    Player p;
    Environment e;
    QApplication a(argc, argv);

    GameWidget g{nullptr,nullptr,nullptr};
    BoardSetup b{nullptr,&g,make_shared<Environment>(e)};
    CharacterSelect c{nullptr,&b,make_shared<Player>(p)};

    c.show();
    return QApplication::exec();
}
