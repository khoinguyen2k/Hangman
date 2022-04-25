#ifndef PIXEL_H
#define PIXEL_H

#include "Position.h"
class Game;

enum UserInput { NO_INPUT = 0, KEY_EXIT, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class Pixel{
   Position position;
   Game* game;
   Direction direction;
   int color;
public:
   Pixel(Game* _game);
   Direction changeDirection(UserInput input);
   void handleInput(UserInput input);
   void processing();
};

#endif
