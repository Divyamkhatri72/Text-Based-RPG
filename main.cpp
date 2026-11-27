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

    shared_ptr<Player> P=make_shared<Player>(p);
    shared_ptr<Environment> E=make_shared<Environment>(e);

    GameWidget g{nullptr,E,P};
    BoardSetup b{nullptr,&g,E};
    CharacterSelect c{nullptr,&b,P};

    c.show();
    return QApplication::exec();
}
