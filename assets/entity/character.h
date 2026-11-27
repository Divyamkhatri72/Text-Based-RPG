#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"
#include "item.h"
#include <vector>

using namespace std;

class Environment;
class Player;

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

    void onRemove();                        //overrides the onRemove function of the entity class
    void setRaceStats();
    void updateModifier();
    void attacking(Character& enemy);
    void defend(Character& enemy);
    void defeat(Player& player);
};

class Player : public Character{
public:
    Player();
    void onRemove();
    void pickUp(Item item);
    void move(int direction);
    void victory(Character& enemy);
    void defeat();

private:
    int _gold;
};

#endif // CHARACTER_H
