#include "tilelist.h"

TileList::TileList()
{


}

void TileList::Add(shared_ptr<Entity> e)
{
    if(_list.empty())
        _list.push_back({e,
                         _barrier,
                         _barrier,
                         _barrier,
                         _barrier});
    else
    {
        _list.back().right=e;
        _list.push_back({e,_list.back().content,_barrier});
    }
}

void TileList::OverrideAt(int i, shared_ptr<Entity> e)
{
    if(_list[i].left!=_barrier)
    {
        _list[i-1].right=e;
    }
    if(_list[i].right!=_barrier)
    {
        _list[i+1].right=e;
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

void TileList::BindBelow(TileList t)
{
    if(t._list.size()==this->_list.size())
    {
        for (int i=0;i<static_cast<int>(_list.size());i++)
        {
            this->_list[i].down=t._list[i].content;
            t._list[i].up=this->_list[i].content;
        }
    }

}

TileList::~TileList()
{


}