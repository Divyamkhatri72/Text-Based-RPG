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
#include <random>
#include <vector>

using namespace std;

class Environment
{
public:
    explicit Environment(int x, int y,Player p);
    void ReceiveCommand(char c);

    void Rescale(int x,int y);

    bool *IsDayTime();
    int X();
    int Y();
private:
    int _x;
    int _y;
    int _nrOfMoves;
    bool _isDaytime;
    shared_ptr<Player> _player;
    vector<TileList> _gameGrid;
    random_device _rnd;

    Entity _empty;
};

#endif // ENVIRONMENT_H

