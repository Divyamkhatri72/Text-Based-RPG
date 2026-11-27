#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

enum class ItemType{ weapon, armour, shield, ring };

enum class WeaponType{ sword, dagger };
enum class ArmourType{ plate, leather };
enum class ShieldType{ large, small };
enum class RingType{ life, strength };

class Item : public Entity{
private:
    ItemType _type;
    int _subtype;
    int _weight{};
    int _modifier{};

public:
    Item(ItemType type, int subtype);

    ItemType getType() const { return _type; }
    int getSubtype() const { return _subtype; }
    int getModifier() const { return _modifier; }

    void onRemove() override;
    void effect();
};

#endif // ITEM_H