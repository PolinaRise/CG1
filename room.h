#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include "Tiles.h"
#include <vector>
#include <set>

class room {
    std::vector <Tile*> room_;
    std::pair <int, int> size_ {0, 0};
public:
    room(char cur);
    void DrawRoom (Image &screen);
    void Play (Player *player, Image &screen);
    std::set<int> GetTiles(Player *player);
};


 #endif