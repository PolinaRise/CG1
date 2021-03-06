#include "Map.h"
#include <fstream>
#include <string>
#include <vector>

Map::Map (Player *player, const std::string &a_path){
    
    std::ifstream mapfile(a_path);          
    std::string str;

    while (std::getline(mapfile, str)) {
       
        
        map.reserve(map.size() + str.length());

        for (auto c: str)
            map.push_back(room(c));

    }

};