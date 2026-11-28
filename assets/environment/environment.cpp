/**
 * @file environment.cpp
 * @author Radu Dimitrie Lecca
 * @brief ...
 * @version 0
 * @date
 */
#include "assets/environment/environment.h"
#include "assets/environment/tilelist.h"
#include "qobject.h"
#include <random>

/**
 * @brief Environment::Environment : Constructor for the environment
 * @param p
 */
Environment::Environment(shared_ptr<Player> p)
{
    _player=p;
}
bool *Environment::IsDayTime(){
    return &_isDaytime;
}

/**
 * @brief Environment::ReceiveCommand
 * @param c : command
 */
void Environment::ReceiveCommand(QChar c)
{
    /// Count that a move was made pre-amptively
    _nrOfMoves++;
    switch(c.toLatin1()){
    case 'N':
        /// if the node above the player's current one doesn't point to an enemy, item or a barrier
        ///     make that one point to the player instead
        ///     make the node that previously pointed to the player point to the _empty entity instead
        break;
    case 'E':
        /// if the node to the right of the player's current one doesn't point to an enemy, item or a barrier
        ///     make that one point to the player instead
        ///     make the node that previously pointed to the player point to the _empty entity instead
        ///
        break;
    case 'W':
        /// if the node to the left of the player's current one doesn't point to an enemy, item or a barrier
        ///     make that one point to the player instead
        ///     make the node that previously pointed to the player point to the _empty entity instead
        break;
    case 'S':
        /// if the node above the player's current one doesn't point to an enemy, item or a barrier
        ///     make that one point to the player instead
        ///     make the node that previously pointed to the player point to the _empty entity instead
        break;
    case 'p':
        /// if any node around the player's current one points to an item
        ///     add the item to the player's inventory
        ///     remove item off the board
        break;
    case 'a':
        /// if any node around the player's current points to an enemy
        ///     attack enemy
        break;
    case 'l':
        //shows board, or at least some of it
        break;
    case 'i':
        //shows inventory
        break;
    case 'e':
        //exit the game
        return;
        break;
    default:
        /// Command is not recognised, therefore it is no longer counted as a valid move
        _nrOfMoves--;
        break;
    }
    ///> If 5 command were succesfully executed, the time is switched from day to night or vice-versa
    if(_nrOfMoves>=5)
    {
        _isDaytime=_isDaytime?false:true;
        _nrOfMoves=0;
    }
}

/**
 * @brief Environment::setGridSize
 * @param x : width
 * @param y : height
 */
void Environment::setGridSize(int x, int y)
{
    mt19937 _randomEngine(std::time(nullptr)); /// Random number generator
    uniform_int_distribution<int> entityType{0, 2}; /// Random number between 0 and 2, 0- empty space, 1- item , 2 - enemy
    uniform_int_distribution<int> itemVariation{0, 5};/// Uniform distributor, outputs a random number between 0-5, used to determine which items will appear on the board
    uniform_int_distribution<int> raceVariation{0, 5};/// Uniform distributor, outputs a random number between 0-5, used to determine the race of each enemy on the board

    /// assign private reference values for the size of the board
    _width=x;
    _height=y;

    /// Add a set number ( change x to something else ) of randomly selected items
    for(int i=0;i<x;i++)
    {
        Item newItem{static_cast<ItemType>(itemVariation(_randomEngine))};
        _items.push_back(newItem);
    }


    /// Add a set number ( change x to something else ) of randomly selected items
    for(int i=0;i<x;i++)
    {
        Character newEnemy{static_cast<Race>(raceVariation(_randomEngine)),make_shared<bool>(_isDaytime)};
        _enemies.push_back(newEnemy);
    }

    int addedEnemies{0};/// counter for how many enemies from the environment's memory were already added to the board, used to prevent two nodes from pointing to the same enemy
    int addedItems{0};/// counter for how many items from the environment's memory were already added to the board, used to prevent two nodes from pointing to the same item

    /// For every row of items in the grid
    for(int i=0;i<x; i++)
    {
        /// New row, must be cleared at the end of the loop
        TileList t;
        /// for every collumn in the row
        for( int j=0;j<y;j++)
        {
            /// switch for one of three random options for an item
            switch (entityType(_randomEngine)) {
            ///empty space
            case 0:
                ///Add empty space
                t.Add(make_shared<Entity>(_empty));
                break;
            /// item
            case 1:
                ///if there are still items to be added
                if(addedItems<static_cast<int>(_items.size()))
                {
                    /// add a node pointing to that item
                    t.Add(make_shared<Item>(_items[addedItems]));
                    ///count item as added
                    addedItems++;
                }
                ///else
                else
                    ///Add empty space
                     t.Add(make_shared<Entity>(_empty));
                break;

            //enemy
            case 2:
                ///if there are still enemies to be added
                if(addedEnemies<static_cast<int>(_enemies.size()))
                {
                    ///add a node pointing to that enemy
                    t.Add(make_shared<Character>(_enemies[addedEnemies]));
                    ///count enemy as placed on the board
                    addedEnemies++;
                }
                else
                    ///Add empty space
                    t.Add(make_shared<Entity>(_empty));
                break;
            default:
                break;
            }
        }
        ///if there is a row already present
        if(i>0)
        {
            ///Attach new row as below the current one
            _gameGrid[i-1].BindBelow(t);

        }
        ///Add row to the grid
        _gameGrid.push_back(t); /// < PLEASE ADD FLAG FOR WHEN ROW IS NOT THE SAME LENGTH AS THE PREVIOUS ONES
        /// may need to clear the 't' tilelist row before the for loop starts again. May need testing
    }

    /// Assign the node in the middle of the board to the player character
    _gameGrid[_width/2].OverrideAt(_height/2,_player);
}

/**
 * @brief Environment::PlacePlayer : Assigns a player to the environment. Needs name change
 * @param p
 */
void Environment::PlacePlayer(shared_ptr<Player> p)
{
    _player=p;
}

/**
 * @brief Environment::getTileEntity
 * @param x
 * @param y
 * @return the shared pointer to the entity at those coordinates
 */
shared_ptr<Entity> Environment::getTileEntity( int x, int y)
{
    if((x<_width && x>0)
        &&
        (y<_height && y>0))
    {
        return _gameGrid[y].GetEntityFromIndex(x);
    }
    else
        return nullptr;
}
/**
 * @brief Environment::Width : returns the current width of the environment's grid
 * @return integer value
 */
int Environment::Width(){
    return _width;
}

/**
 * @brief Environment::Height : returns the current height of the environment's grid
 * @return integer value
 */
int Environment::Height(){
    return _height;
}
