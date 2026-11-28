/**
 * @file environment.h
 * @author Radu Dimitrie Lecca
 * @brief ...
 * @version 0
 * @date
 */

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
/**
 * @brief The Environment class
 */
#include "assets/entity/character.h"
#include "assets/entity/entity.h"
#include "assets/environment/tilelist.h"
#include "qobject.h"

#include <vector>

using namespace std;

/**
 * @brief The Environment class : This is the area where data for items and enemies is stored, where the grid board is saved and determines where everything is placed and where the player's input is processed.
 *
 */
class Environment
{
public:
    /**
     * @brief Environment : Constructor. Might need to be deleted from entity.cpp and have it not require a pointer to the player
     * @param p
     */
    explicit Environment(shared_ptr<Player> p=nullptr);

    /**
     * @brief ReceiveCommand: Function which retrieves text input from the game's UI and executes as a command.
     * This function is used to manage interractions between the player character and other entities in the same place.
     *
     * @param c : command, the first character of the input is taken, as per the assignment's requirements
     */
    void ReceiveCommand(QChar c);


    bool *IsDayTime();    /// Returns the address for the boolean that dictates whether it is day or night
    /**
     * @brief setGridSize : Used to generate the grid board after instantiation. it is used because the environment is initialized in the main function, before the menu opens.
     * This function is used when submitting the dimensions of the board.
     * @param x : width
     * @param y : height
     */
    void setGridSize(int x, int y);

    int Width();
    int Height();

    /**
     * @brief PlacePlayer : Used so that the environment has a pointer to the player character so that it can interract with the environment. Nees to be re-named
     * @param p : shared pointer to the player
     */
    void PlacePlayer(shared_ptr<Player> p);

    int PlayerX();
    int PlayerY();

    /**
     * @brief getTileEntity : Functions that returns the pointer to the entity at a cetain set of coordinates. Used moreso so that the game UI can access the grid at certain locations to know what to render
     * @param x
     * @param y
     * @return
     */
    shared_ptr<Entity> getTileEntity(int x, int y);


private:

    int _width;
    int _height;
    /**
     * @brief _nrOfMoves : used to determine how many moves/ commands the player has set. Usedin calculating the day/ night cycle
     */
    int _nrOfMoves;
    /**
     * @brief _isDaytime : If true, it is daytime in game, else it is nightime. Characters have pointers to this variable to use for stat calculations.
     */
    bool _isDaytime;
    /**
     * @brief _player : Pointer to the player character. Player character is instantiated in the main function, thus every other component in the game uses pointers to it, like this one.
     */
    shared_ptr<Player> _player;
    /**
     * @brief _gameGrid : Dynamic 2-dimensional list of smart pointers. Used to determine the position of each entity on the board and their access to other entities for various interactions.
     * An entity can interract with another one when it is to either the left, to the right, above it or below it.
     */
    vector<TileList> _gameGrid;
    /**
     * @brief _items : List of items. The section of the environment's memory where the data for the items is stored and where the pointers on the grid point to for items
     */
    vector<Item> _items;
    /**
     * @brief _enemies: List of enemies. The section of the environment's memory where the data for the enemies is stored and where the pointers on the grid point to for enemies.
     */
    vector<Character> _enemies;

    /**
     * @brief _empty : Entity value used to signify an empty space. All empty spaces point to this to mark a spot the player can walk on.
     */
    Entity _empty;

    /**
     * @brief _barrier : Entity value used to signify the limits of the board . The pointers used to signify the edges of the grid point to this object.
     */
    Entity _barrier;
};

#endif // ENVIRONMENT_H

