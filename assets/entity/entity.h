#ifndef ENTITY_H
#define ENTITY_H

class Entity{
    protected:
        int positionX, positionY;

    public:
        virtual void onRemove() = 0;
        virtual ~Entity();
};

#endif // ENTITY_H
