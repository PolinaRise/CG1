#ifndef TILES_H
#define TILES_H

#include "Player.h"
#include "Image.h"
//#include "Map.h"

enum exit_type {
    LEFT,
    RIGHT,
    UP,
    DOWN,
    QUIT,
    STAY
}; 

class Tile {
    Image _image;
    std::string _name;
public:
    std::pair <int, int> _coords {0, 0};
public:   
    Pixel get_pixel(int i, int j) const;
    std::string get_name() const;
    Tile(const std::string &name, const Image &src, int x_s, int y_s);

   void DrawTile(Image &screen, int i, int j);
   virtual exit_type get_state() const = 0;
   
};

class FloorTile: public Tile {  
public:    
    FloorTile();
    exit_type get_state() const {};
};

class WallTile: public Tile {
public:     
   WallTile();
   exit_type get_state() const {};
};




class DoorTile: public Tile{
    exit_type _state = LEFT;
public:    
    DoorTile(exit_type state); 
   exit_type get_state() const;
};

class GoldTile: public Tile {
public:  
    GoldTile();
    exit_type get_state() const {};
};




#endif
