#ifndef TILES_H
#define TILES_H

#include "Player.h"
#include "Image.h"

class Tile {
    Image _image;
    std::string _name;
    std::pair <int, int> _coords {0, 0};
public:   
    Pixel get_pixel(int i, int j) const;
    std::string get_name() const;
    Tile(const std::string &name, const Image &src, int x_s, int y_s);

   void DrawTile(Image &screen, int i, int j);
   
};

class FloorTile: public Tile {  
public:    
    FloorTile();
};

class WallTile: public Tile {
public:     
   WallTile();
};

class DoorTile: public Tile{
public:    
    DoorTile();
};

class GoldTile: public Tile {
public:  
    GoldTile();
};




#endif
