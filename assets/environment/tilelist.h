#ifndef TILELIST_H
#define TILELIST_H

#include "assets/entity/entity.h"
#include <memory>
#include <vector>

using namespace std;

struct TileNode{
    shared_ptr<Entity> prev;
    shared_ptr<Entity> next; 
    shared_ptr<Entity> content;
};

class TileList
{
public:
    TileList();
    void Add(shared_ptr<Entity> e);
    int GetIndexForEntity(shared_ptr<Entity> e );
    shared_ptr<Entity> GetEntityFromIndex(int i);
    void OverrideAt(int i,shared_ptr<Entity> e );

    int Length();
    ~TileList();

private:
    Entity _head;
    Entity _tail;
    vector<TileNode> _list;
};

#endif // TILELIST_H
