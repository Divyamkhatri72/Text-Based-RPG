#ifndef ENTITY_H
#define ENTITY_H

class Entity{
    protected:
        int positionX, positionY;

    public:
        Entity();
        void onRemove();
        ~Entity();
};

#endif // ENTITY_H
