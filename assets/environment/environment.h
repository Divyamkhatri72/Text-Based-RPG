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

#include <vector>

using namespace std;

class Environment
{
public:
    explicit Environment(shared_ptr<Player> p=nullptr);
    void ReceiveCommand(char c);
    bool *IsDayTime();
    void setGridSize(int x, int y);
    int Width();
    int Length();
    void PlacePlayer(shared_ptr<Player> p);
private:
    int _width;
    int _height;
    int _nrOfMoves;
    bool _isDaytime;
    shared_ptr<Player> _player;
    vector<TileList> _gameGrid;


    Entity _empty;
};

#endif // ENVIRONMENT_H

