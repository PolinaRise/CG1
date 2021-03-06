#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include "room.h"

class Map 
{   
    std::vector <room> map;
  
public:
    Map (Player *player, const std::string &a_path);
};

#endif