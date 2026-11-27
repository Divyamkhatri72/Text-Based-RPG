#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"
#include "item.h"
#include <vector>

using namespace std;

class Environment;

enum class Race{
    Human,
    Elf,
    Dwarf,
    Hobbit,
    Orc
};

class Character : virtual public Entity{
protected:
    Race _race;
    bool _isDay;
private:
    int _Attack, _Defence, _Health, _Strength;
    float _AttackChance, _DefenceChance;
    vector<Item> inventory;

public:
    explicit Character(Race _race, bool isDay);
    int attack, defence, health, strength;
    float attackChance, defenceChance;
    void onRemove();
    void setRaceStats();
    void updateModifier();
    void attacking();
    void defend();
    void defeat();
    void showStats();
};

class Player : public Character{
public:
    Player();
    void onRemove();
    void pickUp();
    void move();
};

#endif // CHARACTER_H
