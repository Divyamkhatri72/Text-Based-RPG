#ifndef NODELIST_H
#define NODELIST_H

#include "assets/entity/entity.h"
#include <memory>
#include <random>
using namespace std;
class NodeList
{
private:
    Entity _header;
    Entity _footer;
    random_device _random;
    Entity ReturnRandEntity();

public:
    NodeList(int length, unique_ptr<Entity> emptyRef);


};

#endif // NODELIST_H