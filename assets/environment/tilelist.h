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
    ~TileList();

private:
    Entity _head;
    Entity _tail;
    vector<TileNode> _list;
};

#endif // TILELIST_H
