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
#include <random>
#include <vector>

using namespace std;

class Environment
{
public:
    explicit Environment(int x, int y,Player *p=nullptr);
    void ReceiveCommand(char c);

    void Rescale(int x,int y);

    bool *IsDayTime();
    void setGridSize();
    int getLength();
    int getWidth();
private:
    int _x;
    int _y;
    int _nrOfMoves;
    bool _isDaytime;
    Player *_player;
    vector<vector<Entity>> _gameGrid;
    random_device _rnd;
};

#endif // ENVIRONMENT_H

