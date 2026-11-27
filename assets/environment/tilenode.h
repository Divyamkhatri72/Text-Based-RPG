#ifndef TILENODE_H
#define TILENODE_H

#include "assets/entity/entity.h"
#include <memory>
using namespace std;


class TileNode
{
private:
    shared_ptr<Entity> _content;
    shared_ptr<Entity> _prev;
    shared_ptr<Entity> _next;
public:
    TileNode(shared_ptr<Entity> e,shared_ptr<Entity> p,shared_ptr<Entity> n);
    void Assign(shared_ptr<Entity> e);

};

#endif // TILENODE_H
