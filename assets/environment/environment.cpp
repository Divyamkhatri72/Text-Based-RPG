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


Environment::Environment(shared_ptr<Player> p)
{
    _player=p;
}
bool *Environment::IsDayTime(){
    return &_isDaytime;
}

void Environment::ReceiveCommand(QChar c)
{
    _nrOfMoves++;
    switch(c.toLatin1()){
    case 'N':
        //go forward
        break;
    case 'E':
        //go east
        break;
    case 'W':
        //go west
        break;
    case 'S':
        //go south
        break;
    case 'p':
        //pick up item
        break;
    case 'a':
        //attack if enemy is nearby
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
        //command not recognised, does not count as command
        _nrOfMoves--;
        break;
    }
    ///> Switches daytime to nighttime
    if(_nrOfMoves>=5)
    {
        _isDaytime=_isDaytime?false:true;
        _nrOfMoves=0;
    }
}

void Environment::setGridSize(int x, int y)
{
    mt19937 _randomEngine(std::time(nullptr));
    uniform_int_distribution<int> entityType{0, 2};
    uniform_int_distribution<int> itemVariation{0, 5};
    uniform_int_distribution<int> raceVariation{0, 5};

    _width=x;
    _height=y;

    for(int i=0;i<x;i++)
    {
        Item newItem{static_cast<ItemType>(itemVariation(_randomEngine))};
        _items.push_back(newItem);
    }

    for(int i=0;i<x;i++)
    {
        Character newEnemy{static_cast<Race>(raceVariation(_randomEngine)),make_shared<bool>(_isDaytime)};
        _enemies.push_back(newEnemy);
    }

    int addedEnemies{0};
    int addedItems{0};

    for(int i=0;i<x; i++)
    {
        TileList t;
        for( int j=0;j<y;j++)
        {
            switch (entityType(_randomEngine)) {
            case 0:
                t.Add(nullptr);
                break;
            case 1:
                if(addedItems<static_cast<int>(_items.size()))
                {
                    t.Add(make_shared<Item>(_items[addedItems]));
                    addedItems++;
                }
                else
                    t.Add(nullptr);
                break;
            case 2:
                if(addedEnemies<static_cast<int>(_enemies.size()))
                {
                    t.Add(make_shared<Character>(_enemies[addedEnemies]));
                    addedEnemies++;
                }
                else
                    t.Add(nullptr);
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
        _gameGrid.push_back(t);


    }

    _gameGrid[_width/2].OverrideAt(_height/2,_player);
}

void Environment::PlacePlayer(shared_ptr<Player> p)
{
    _player=p;
}

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

int Environment::Width(){
    return _width;
}

int Environment::Height(){
    return _height;
}
