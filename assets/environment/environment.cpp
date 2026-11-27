/**
 * @file environment.cpp
 * @author Radu Dimitrie Lecca
 * @brief ...
 * @version 0
 * @date
 */
#include "assets/environment/environment.h"


Environment::Environment(int x, int y,Player *p)
{
    _player=p;
    for(int i=0;i<x; i++)
    {
        vector<TileNode> row;
        for( int j=0;j<y;j++)
        {
            /// add random enemies/ weapons on the field
            ///


        }
        _gameGrid.push_back(row);
    }

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

int Environment::X(){
    return _x;
}

int Environment::Y(){
    return _y;
}
