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
#include "assets/entity/entity.h"
#include "assets/environment/tilenode.h"
#include <vector>

using namespace std;

class Environment
{
public:
    Environment(int x, int y);
    void ReceiveCommand(char c);
private:
    int _x;
    int _y;
    int _nrOfMoves;
    bool _isDaytime;
    Entity _player;
    vector<Entity> _weapons;
    vector<Entity> _enemies;
    vector<vector<TileNode>>_gameGrid;


};

#endif // ENVIRONMENT_H

