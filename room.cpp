#include "room.h"
#include "Tiles.h"
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <iostream>
#include "Image.h"

room::room (char cur) {
    if (cur != '.'){
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

            bool is_first;
            if (size_.second == 1) {
                is_first = 1;
            } else {
                is_first = 0;
            }

            room_.reserve(room_.size() + str.length());

            for (int i = 0; i < str.length(); i++) {
                
                switch (str[i])
                {
                case '@': //player
                    //???/
                    break;
                case '#': //wall 
                    room_.push_back(new WallTile());
                    break;
                case '.': //floor
                    room_.push_back(new FloorTile());
                break;
                case 'x'://exit could be only on walls 
                    exit_type x;
                    
                    if (i == 0) {
                        x = LEFT;
                    }
                        else if (i != 0) {
                        x = RIGHT;
                        } else if (is_first) {
                            x = UP;
                        } else {
                            x = DOWN;
                        }
                        
                    
                    room_.push_back(new DoorTile(x));
                    break;
                case 'Q'://quit
                    room_.push_back(new DoorTile(QUIT));
                    
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

       
    } else if (cur != '.') {
        //you wiin tile 
    } else {
        //you dead tile 
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

exit_type room::Play(Player *player, Image &screen){
   
    auto tiles_idx = GetTiles(player);
    for (auto i: tiles_idx) {
        auto cur_name = room_[i]->get_name();
        if (cur_name == "wall") {
            player->Collision();
        } else if (cur_name == "door") {
            return room_[i]->get_state();

        } else if (cur_name == "gold") {
            k_gold++;
            int x_s = room_[i]->_coords.first;
            int y_s = room_[i]->_coords.second;
            room_[i] = new FloorTile();
            room_[i]->DrawTile(screen, x_s, y_s);
            //Картинка о том, что буфер увеличился
            
        } else {

        }
    }
    return STAY;
}


void room::DrawRoom (Image &screen) {
    std::cout<<"DRAW"<<std::endl;
    for (int i = 0 ; i < size_.second; ++i)
        for (int j = 0; j < size_.first; ++j) {
            int x = (room_.size() - size_.first) - i * size_.first + j;
            room_[x]->DrawTile(screen, i, j); 
        }
            
} 

