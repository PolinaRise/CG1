#include "room.h"
#include "Tiles.h"
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <iostream>
#include "Image.h"
room::room (char cur) {
    if (cur != 'E'){
        std::string path = "resources/maps/";
        path += cur; 
        path += ".txt";

        std::ifstream roomfile(path); 
        
        std::string str;

        while (std::getline(roomfile, str)) {
           
            size_.second++;
            if (size_.first == 0) {
                size_.first = str.length();
            }

            room_.reserve(room_.size() + str.length());

            for (auto c: str) {
                
                switch (c)
                {
                case '@': //player
                    
                    break;
                case '#': //wall 
                    room_.push_back(new WallTile());
                    break;
                case '.': //floor
                    room_.push_back(new FloorTile());
                break;
                case 'x'://exit 
                    room_.push_back(new DoorTile());
                    break;
                case 'Q'://quit
                    room_.push_back(new DoorTile());
                    break;
                case 'G'://gold
                    room_.push_back(new GoldTile());
                    break;
                default:
                    room_.push_back(new FloorTile());
                    break;
                }
            }
        }

       
    }
}



#define matind(s, i, j) i * s + j


std::set<int> room::GetTiles(Player *player){
    std::set<int> tiles_idx;
    const std::vector<int> dx{0,0,1,1};
    const std::vector<int> dy{0,1,0,1};
    for (int i = 0; i < 4; i++) {
        int x = player->coords.x + dx[i] * (16 - 1);
        int y = player->coords.y + dy[i] * (16 - 1);
        int ti = x/16;
        int tj = y/16;
        tj = size_.second - tj - 1;
        
        tiles_idx.insert(matind(size_.first, tj, ti));
      }
    return tiles_idx;
}
void room::Play(Player *player, Image &screen){
   
    auto tiles_idx = GetTiles(player);
    for (auto i: tiles_idx) {
        auto cur_name = room_[i]->get_name();
        if (cur_name == "wall") {
            player->Collision();
        } else if (cur_name == "door") {
            /* code */
        } else if (cur_name == "quit") {
            /* code */
        } else if (cur_name == "gold") {
            /* code */
        } else {

        }
    }
}


void room::DrawRoom (Image &screen) {
    
    for (int i = 0 ; i < size_.second; ++i)
        for (int j = 0; j < size_.first; ++j) {
            int x = (room_.size() - size_.first) - i * size_.first + j;
            room_[x]->DrawTile(screen, i, j); 
        }
            
} 

