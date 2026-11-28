#ifndef TILELIST_H
#define TILELIST_H

#include "assets/entity/entity.h"
#include <memory>
#include <vector>

using namespace std;

///structure of

/**
 * @brief The TileNode class: Nodes for the list, serving as tiles on the board and arranged in a grid-like pattern.
 * A tile node has an address to the entity that is "located on that tile" and addresses for the entities "located" to the left,right,in front of and behind the entity.
 */
struct TileNode{
    shared_ptr<Entity> content;
    shared_ptr<Entity> left;
    shared_ptr<Entity> right;
    shared_ptr<Entity> up;
    shared_ptr<Entity> down;
};

/**
 * @brief The TileList class : A 'list' of tile nodes. Considerable as a row in the environment's grid.
  */
class TileList
{
public:
    TileList();
    /**
     * @brief Add : add node at the end of the tilelist, like the push command for a vector
     * @param e : entity to add
     */
    void Add(shared_ptr<Entity> e);
    /**
     * @brief GetIndexForEntity : returns the index of entity 'e' in the list, mainly used to return the address of the player atm.
     * @param e : entity in the row to locate in the tilelist
     * @return integer that indicates where in the list is 'e'
     */
    int GetIndexForEntity(shared_ptr<Entity> e );
    /**
     * @brief GetEntityFromIndex : return the index pointing to an entity
     * @param i
     * @return the entity at index 'i'
     */
    shared_ptr<Entity> GetEntityFromIndex(int i);
    /**
     * @brief OverrideAt : hanges the address at index 'i' so that entity 'e' takes the place of the entity that was precviously at that address.
     * Used mainly for the following:
     * -to assign the initial position of the player after the board was generated [ environment ]
     * -to change what tile is pointing at the player ( where the player is positioned ) on the board
     * -have tiles pointing to items that were collected no longer point to them
     * -have tiles pointing to defeated enemies no longer point to them
     * @param i
     * @param e
     */
    void OverrideAt(int i,shared_ptr<Entity> e );
    /**
     * @brief BindBelow : Binds the row 't' below this one by having each node in 't' connect to below the corresponding node in 'this' tilenode
     * Used when generating the grid
     * @param t
     */
    void BindBelow(TileList t);

    ~TileList();/// destructor . May use later to clean up the row

private:
    /**
     * @brief _barrier : Node which, when pointed to, marks that the node is at the edge of the grid. Is a pointer whose address is in the environment class
     */
    shared_ptr<Entity> _barrier;

    /**
     * @brief _list : The list of nodes on the row
     */
    vector<TileNode> _list;
};

#endif // TILELIST_H
