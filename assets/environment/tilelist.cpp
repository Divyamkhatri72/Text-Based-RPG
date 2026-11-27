#include "tilelist.h"

TileList::TileList()
{


}

void TileList::Add(shared_ptr<Entity> e)
{
    if(_list.empty())
        _list.push_back({e,make_shared<Entity>(_head),make_shared<Entity>(_tail)});
    else
    {
        _list.back().next=e;
        _list.push_back({e,_list.back().content,make_shared<Entity>(_tail)});

    }

}

TileList::~TileList()
{


}