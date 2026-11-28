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

void TileList::OverrideAt(int i, shared_ptr<Entity> e)
{
    if(_list[i].prev!=make_shared<Entity>(_head))
    {
        _list[i-1].next=e;
    }
    if(_list[i].next!=make_shared<Entity>(_tail))
    {
        _list[i+1].prev=e;
    }

    _list[i].content=e;
}

int TileList::GetIndexForEntity(shared_ptr<Entity> e)
{
    for(int i=0;i<static_cast<int>(_list.size());i++)
        if(_list[i].content==e)
            return i;
    return -1;
}

shared_ptr<Entity> TileList::GetEntityFromIndex(int i){
    return _list[i].content;
}

TileList::~TileList()
{


}