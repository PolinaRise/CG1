#ifndef MAIN_PLAYER_H
#define MAIN_PLAYER_H

#include "Image.h"
#include "Tiles.h"

struct Point
{
  int x;
  int y;
};

enum class MovementDir
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

struct Player
{
  explicit Player(Point pos = {.x = 10, .y = 10}) :
                 coords(pos), old_coords(coords) {};

  bool Moved() const;
  void ProcessInput(MovementDir dir);
  void Draw(Image &screen);
  void Collision();


Point coords {.x = 10, .y = 10};
  private:
  Point old_coords {.x = 0, .y = 0};
  Pixel color {.r = 255, .g = 255, .b = 0, .a = 255};
  int move_speed = 4;

};

#endif //MAIN_PLAYER_H
