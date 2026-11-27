#include "character.h"
#include <random>
#include <QKeyEvent>

Character::Character(Race race, bool isDay)
{
    _race=race;
    _isDay=isDay;

    updateModifier();
}

void Character::setRaceStats(){
    switch(_race){
    case Race::Human:
        _Attack = 30;
        _AttackChance = 2.0f/3.0f;
        _Defence = 20;
        _DefenceChance = 1.0f/2.0f;
        _Health = 60;
        _Strength = 100;
        break;

    case Race::Elf:
        _Attack = 40;
        _AttackChance = 1.0f;
        _Defence = 10;
        _DefenceChance = 1.0f/4.0f;
        _Health = 40;
        _Strength = 70;
        break;

    case Race::Dwarf:
        _Attack = 30;
        _AttackChance = 2.0f/3.0f;
        _Defence = 20;
        _DefenceChance = 2.0f/3.0f;
        _Health = 50;
        _Strength = 130;
        break;

    case Race::Hobbit:
        _Attack = 25;
        _AttackChance = 1.0f/3.0f;
        _Defence = 20;
        _DefenceChance = 2.0f/3.0f;
        _Health = 70;
        _Strength = 85;
        break;

    case Race::Orc:
        if(_isDay){
            _Attack = 25;
            _AttackChance = 1.0f/4.0f;
            _Defence = 10;
            _DefenceChance = 1.0f/4.0f;
        }else{
            _Attack = 45;
            _AttackChance = 1.0f;
            _Defence = 25;
            _DefenceChance = 1.0f/2.0f;
        }
        _Health = 50;
        _Strength = 130;
        break;
    }
}

void Character::updateModifier(){
    setRaceStats();

    attack = _Attack;
    defence = _Defence;
    health = _Health;
    strength = _Strength;
    attackChance = _AttackChance;
    defenceChance = _DefenceChance;

    for(const Item& item : inventory){
        attack   += item.getAttackMod();
        defence  += item.getDefenceMod();
        health   += item.getHealthMod();
        strength += item.getStrengthMod();
    }

    if(health < 1) health = 1;   //Note: a ring shouldn't kill the character
}

void Character::onRemove()
{

}

void Character::defend(Character& enemy){
    mt19937 mt(time(0));
    int roll;
    bool success;

    roll = mt()%12;    //it is 12 because that's the lcm of 2,3 and 4 which are the denominator for defence chance making calculations easier

    success = roll < 12*_DefenceChance;

    if(success){
        switch(_race){
        case Race::Human:
            break;

        case Race::Elf:
            health++;
            break;

        case Race::Dwarf:
            break;

        case Race::Hobbit:
            health -= mt()%6;
            break;

        case Race::Orc:
            int damage;
            if(_isDay){
                damage = enemy.attack - defence;
                damage /=4;
                health -= damage;
            }else{
                health++;
            }
            break;

        }
    }else{
        int damage;
        damage = enemy.attack - defence;            //note that attack and defence are calculated by taking items into account
        health -= damage;
    }

}

void Character::attacking(Character& enemy){
    mt19937 mt(time(0));
    int roll{};
    bool success;

    roll = mt()%12;
    success = roll < 12*attackChance;

    if(success){
        enemy.defend(*this);
    }
}

void Character::defeat(Player& player){
    player.victory(*this);
}

void Player::move(int direction){
    switch(direction){
    case Qt::Key_Up:
        positionY++;

    }
}