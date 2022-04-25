#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Pixel.h"
using namespace std;

class Game{
   vector< vector<int>> board; //luu chi so mau cua pixel va -1 neu ko co gi
   Pixel pixel;
   bool running;
public:
   Game();
   vector< vector<int>> getBoard() const { return board; }
   bool isRunning() const { return running; }
   void changeCellId(Position pos, int color);
   void handleInput(UserInput input);
   void processing();
};

#endif
