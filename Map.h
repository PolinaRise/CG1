#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include "room.h"
#include "Tiles.h"



class Map 
{   
    std::vector <room> map;
    std::pair <int, int> size_ {0, 0};
    int current_room = 1;
public:
    Map (Player *player, const std::string &a_path);
    void Play (Player *player, Image &screenBuffer);
};

#endif