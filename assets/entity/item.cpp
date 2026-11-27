#include "item.h"

Item::Item(ItemType type) : _type(type){
    switch(type){
    case ItemType::Sword:
        _name = "Sword";
        _category = ItemCategory::Weapon;
        _weight = 10;
        _attackMod = 10;
        break;

    case ItemType::Dagger:
        _name = "Dagger";
        _category = ItemCategory::Weapon;
        _weight = 5;
        _attackMod = 5;
        break;

    case ItemType::PlateArmour:
        _name = "Plate Armour";
        _category = ItemCategory::Armour;
        _weight = 40;
        _defenceMod = 10;
        _attackMod = -5;
        break;

    case ItemType::LeatherArmour:
        _name = "Leather Armour";
        _category = ItemCategory::Armour;
        _weight = 20;
        _defenceMod = 5;
        break;

    case ItemType::LargeShield:
        _name = "Large Shield";
        _category = ItemCategory::Shield;
        _weight = 30;
        _defenceMod = 10;
        _attackMod = -5;
        break;

    case ItemType::SmallShield:
        _name = "Small Shield";
        _category = ItemCategory::Shield;
        _weight = 10;
        _defenceMod = 5;
        break;

    case ItemType::RingOfLife:
        _name = "Ring of Life";
        _category = ItemCategory::Ring;
        _weight = 1;
        _healthMod = 10;
        break;

    case ItemType::RingOfStrength:
        _name = "Ring of Strength";
        _category = ItemCategory::Ring;
        _weight = 1;
        _strengthMod = 50;
        _healthMod = -10;
        break;
    }
}

void Item::onRemove(){
    //remove the item from the board
}