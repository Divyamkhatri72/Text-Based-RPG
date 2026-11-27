#include "tilelist.h"

TileList::TileList()
{


}


void TileList::Add(shared_ptr<Entity> e)
{
    _list.push_back({e,_list.back().content,make_shared<Entity>(_tail)});
}