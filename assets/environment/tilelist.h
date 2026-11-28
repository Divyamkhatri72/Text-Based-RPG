#ifndef TILELIST_H
#define TILELIST_H

#include "assets/entity/entity.h"
#include <memory>
#include <vector>

using namespace std;

struct TileNode{
    shared_ptr<Entity> content;
    shared_ptr<Entity> left;
    shared_ptr<Entity> right;
    shared_ptr<Entity> up;
    shared_ptr<Entity> down;


};

class TileList
{
public:
    TileList();
    void Add(shared_ptr<Entity> e);
    int GetIndexForEntity(shared_ptr<Entity> e );
    shared_ptr<Entity> GetEntityFromIndex(int i);
    void OverrideAt(int i,shared_ptr<Entity> e );
    void BindBelow(TileList t);
    ~TileList();

private:
    shared_ptr<Entity> _barrier;
    vector<TileNode> _list;
};

#endif // TILELIST_H
