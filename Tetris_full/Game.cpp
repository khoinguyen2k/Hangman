#include "Game.h"

Game::Game(): board(10, vector<int>(20, -1)), pixel(this), running(true){
   board[0][0] =0;
}
void Game::changeCellId(Position pos, int color){
   board[pos.x][pos.y] =color;
}
void Game::handleInput(UserInput input){
   if (input ==KEY_EXIT) { running =false; return; }
   pixel.handleInput(input);
}
void Game::processing(){
   pixel.processing();
}
