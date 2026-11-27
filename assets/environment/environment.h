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
#include "assets/environment/tilenode.h"
#include <vector>

using namespace std;

class Environment
{
public:
    explicit Environment(int x, int y,Player *p);
    void ReceiveCommand(char c);
    bool *IsDayTime();
    void setGridSize();
    int getLength();
    int getWidth();
private:
    int _x;
    int _y;
    int _nrOfMoves;
    bool _isDaytime;
    Player* _player;

    vector<Item> _weapons;
    vector<Character> _enemies;
    vector<vector<TileNode>>_gameGrid;
};

#endif // ENVIRONMENT_H

