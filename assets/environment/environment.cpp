/**
 * @file environment.cpp
 * @author Radu Dimitrie Lecca
 * @brief ...
 * @version 0
 * @date
 */
#include "assets/environment/environment.h"
#include "assets/environment/tilelist.h"
#include <random>


Environment::Environment(shared_ptr<Player> p)
{
    _player=p;
}
bool *Environment::IsDayTime(){
    return &_isDaytime;
}

void Environment::ReceiveCommand(char c)
{
    _nrOfMoves++;
    switch(c){
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
    random_device _rnd;
    mt19937 e{static_cast<mt19937>(_rnd())};
    uniform_int_distribution<int> entityType{0, 2};
    uniform_int_distribution<int> entityVariation{0, 5};
    for(int i=0;i<x; i++)
    {
        TileList t;
        for( int j=0;j<y;j++)
        {
            /// add random enemies/ weapons on the field
            ///
                switch (entityType(e)) {
                case 0:
                    ///add empty node
                    t.Add(make_shared<Entity>(_empty));
                    break;

                case 1:
                    //add item
                    t.Add(make_shared<Item>(*new Item(ItemType::Dagger)));
                    break;

                case 2:
                    t.Add(make_shared<Character>(*new Character(Race::Hobbit,make_shared<bool>(_isDaytime))));
                    break;

                default:
                    break;
                }
        }
        _gameGrid.push_back(t);
    }

}

void Environment::PlacePlayer(shared_ptr<Player> p)
{

}

int Environment::Width(){
    return _width;
}

int Environment::Length(){
    return _height;
}
