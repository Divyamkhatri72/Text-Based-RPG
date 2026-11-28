#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"
#include "item.h"
#include <memory>
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
    shared_ptr<bool> _isDay;
    vector<Item> _inventory;

private:
    int _Attack, _Defence, _Health, _Strength;
    float _AttackChance, _DefenceChance;


public:
    explicit Character(Race _race=Race::Human, shared_ptr<bool> isDay=nullptr);
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
    Player(Race race=Race::Human, string name="");
    void SetDetails(Race race, string name);
    void onRemove();
    void pickUp(Item& item);
    void move(int direction);
    void victory(Character& enemy);
    void defeat();

private:
    int _gold;
    string _name;
};

#endif // CHARACTER_H