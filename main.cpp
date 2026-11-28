#include "assets/environment/environment.h"
#include "assets/widgets/boardsetup.h"
#include "assets/widgets/characterselect.h"
#include "assets/widgets/gamewidget.h"
#include <QApplication>
#include <ctime>
#include <memory>


/**
 * @brief main : Where the game is initialized
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    Player p;///< The place in memory where the player is stored
    Environment e;///< The place in memory where the environment is stored
    QApplication a(argc, argv);

    shared_ptr<Player> P=make_shared<Player>(p);///< Pointer to the player. Used in initializing widgets
    shared_ptr<Environment> E=make_shared<Environment>(e);///< Pointer to environment. Used in initializing widgets

    ///Game window. Here, pointers to the player and environment are used for the game.
    GameWidget g{nullptr,E,P};

    ///Game board setup menu. Here, the menu takes a pointer to the environment,
    /// to have the changes remain after setting up its size,
    /// and to the game menu so it can be opened afterward.
    BoardSetup b{nullptr,&g,E};

    ///Character edit menu. Here, the menu takes pointers to the player character,
    ///  to have the changes remain after closing the menu,
    ///  and to the game board setup menu to open it afterwards.
    CharacterSelect c{nullptr,&b,P};

    c.show();

    return QApplication::exec();
}
