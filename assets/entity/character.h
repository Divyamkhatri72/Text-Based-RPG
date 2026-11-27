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

class Character : public Entity{
private:
    Race _race;

    int _Attack, _Defence, _Health, _Strength;
    float _AttackChance, _DefenceChance;
    vector<Item> inventory;

public:
    Character(Race _race, Environment& environment);
    int attack, defence, health, strength;
    float attackChance, defenceChance;

    void onRemove() override;
    void setRaceStats();
    void updateModifier();
    void attacking();
    void defend();
    void defeat();
    void showStats();
};

class Player : public Character{
public:
    void pickUp();
    void move();
};

#endif // CHARACTER_H
