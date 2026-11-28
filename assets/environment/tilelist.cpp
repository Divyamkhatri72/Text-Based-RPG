#include "tilelist.h"

TileList::TileList()
{}

/**
 * @brief TileList::Add
 * @param e : entity to add to the list
 */
void TileList::Add(shared_ptr<Entity> e)
{
    ///If the list is empty
    if(_list.empty())
        ///Add entity surrounded by barriers
        _list.push_back({e,
                         _barrier,
                         _barrier,
                         _barrier,
                         _barrier});
    //else
    else
    {
        /// have the last node in the list point to 'e' as the next one to its right
        _list.back().right=e;
        /// have 'e' added to the list
        _list.push_back({e,_list.back().content,_barrier,_barrier,_barrier});
    }
}

void TileList::OverrideAt(int i, shared_ptr<Entity> e)
{
    ///If the node doesn't point to a barrier to either the left or the right of the barrier,
    /// assign 'e' as the neighbour of those
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

/**
 * @brief TileList::GetIndexForEntity
 * @param e
 * @return
 */
int TileList::GetIndexForEntity(shared_ptr<Entity> e)
{
    /// for all entities in the list
    for(int i=0;i<static_cast<int>(_list.size());i++)
        /// if the list at this index is equal to 'e'
        if(_list[i].content==e)
            /// return said index
            return i;
    ///otherwise, return -1 as an iinvalid index value
    return -1;
}

/**
 * @brief TileList::GetEntityFromIndex
 * @param i
 * @return
 */
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