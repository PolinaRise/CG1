#include "Tiles.h"

Image wallset("./resources/walls.png");
Image floorset("./resources/floor.png");
Image objset("./resources/obj_set.png");
Image persset("./resources/persons.png");

   
Pixel Tile::get_pixel(int i, int j) const {
    return _image.GetPixel(i, j);
}

std::string Tile::get_name() const {
    return _name;
}

Tile::Tile(const std::string &name, const Image &src, int x_s, int y_s): _image(16, 16, 4), _name(name) {
    for (int i = x_s; i < x_s + 16; ++i)
        for (int j = y_s; j < y_s + 16; ++j)
            _image.PutPixel(i - x_s, j - y_s, src.GetPixel(i, j));
}

void Tile::DrawTile(Image &screen, int i, int j) {
    i *= 16;
    j *= 16;
    _coords.first = i;
    _coords.second = j;
    for (int x = 0; x < 16; ++x)
        for (int y = 0; y < 16; ++y)
            screen.PutPixel(j + x, i + y, this->get_pixel(x, y));
}

  
FloorTile::FloorTile(): Tile("floor", floorset, 16, 16) {};
WallTile::WallTile(): Tile("wall", objset, 16, 16) {};
DoorTile::DoorTile(): Tile("door", wallset, 64, 32) {};
GoldTile::GoldTile(): Tile("gold", objset, 128, 96) {};
