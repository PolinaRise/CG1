#include "Map.h"
#include <fstream>
#include <string>
#include <vector>

Map::Map (Player *player, const std::string &a_path){
    
    std::ifstream mapfile(a_path);          
    std::string str;

    while (std::getline(mapfile, str)) {
       
        size_.second++;
        if (size_.first == 0) {
            size_.first = str.length();
        }

        map.reserve(map.size() + str.length());

        for (auto c: str)
            map.push_back(room(c));

    }

};

void Map::Play (Player *player, Image &screenBuffer){
    map[current_room].DrawRoom(screenBuffer);
    exit_type state = map[current_room].Play(player,screenBuffer);
    //bool is_quit = 0;
    //return;
    //while (!is_quit)  {  
    if (1)  {  

        switch (state)
        {
        case LEFT:
            current_room = current_room - 1 ;
            map[current_room].DrawRoom(screenBuffer);
            //state = map[current_room].Play(player,screenBuffer);
            break;
        
        case RIGHT:
            current_room = current_room + 1 ;
            map[current_room].DrawRoom(screenBuffer);
            //state = map[current_room].Play(player,screenBuffer);
            break;
        
        case UP:
            current_room = current_room - size_.first ;
            map[current_room].DrawRoom(screenBuffer);
            //state = map[current_room].Play(player,screenBuffer);
            break;
        
        case DOWN:
            current_room = current_room + size_.first ;
            map[current_room].DrawRoom(screenBuffer);
            //state = map[current_room].Play(player,screenBuffer);
            break;
        
        case QUIT:
            //current_rooms_quit = 1; 
            //Вывод картинки о выигрыше
            break;
        default:
            //state = map[current_room].Play(player,screenBuffer);
            break;
        }
    }
}