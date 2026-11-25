#include "tilenode.h"

TileNode::TileNode(shared_ptr<Entity> e, shared_ptr<Entity> p, shared_ptr<Entity> n)
{
    _content=e;
    _prev=p;
    _next=n;

}

void TileNode::Assign(shared_ptr<Entity> e)
{
    _content=e;
}