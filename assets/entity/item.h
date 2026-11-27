#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

#include <string>

enum class ItemCategory{
    Weapon,
    Armour,
    Shield,
    Ring
};

enum class ItemType{
    Sword,
    Dagger,
    PlateArmour,
    LeatherArmour,
    LargeShield,
    SmallShield,
    RingOfLife,
    RingOfStrength
};

class Item : virtual public Entity{
private:
    ItemType _type;
    ItemCategory _category;
    std::string _name;
    int _weight{};

    // Changes applied to the owner's stats (negative = decrease)
    int _attackMod{};
    int _defenceMod{};
    int _healthMod{};
    int _strengthMod{};

public:
    explicit Item(ItemType type);

    ItemType getType() const { return _type; }
    ItemCategory getCategory() const { return _category; }
    const std::string& getName() const { return _name; }
    int getWeight() const { return _weight; }

    int getAttackMod() const { return _attackMod; }
    int getDefenceMod() const { return _defenceMod; }
    int getHealthMod() const { return _healthMod; }
    int getStrengthMod() const { return _strengthMod; }

    void onRemove();
};

#endif // ITEM_H