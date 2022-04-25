#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"

#include "Game.h"
using namespace std;

const int SCREEN_WIDTH =480;
const int SCREEN_HEIGHT =640;
const string WINDOW_TITLE ="Testt!!";

const Position START_CORNER(28, 31);
const int MAX_COLOR_NUM =8;
const int PIXEL_SIZE =18;
const int NUM_ROW =20;
const int NUM_COLUMN =10;

static SDL_Window* window;
static SDL_Renderer* renderer;
SDL_Rect setRect(int x, int y, int w, int h);
void draw(SDL_Texture* texture, int x, int y);
void draw(SDL_Texture* texture, SDL_Rect src, int x, int y);

UserInput interpretEvent(SDL_Event e);
void drawPixel(int id_x, int id_y);
void renderGame(const Game& game);

int main(int argc, char* agrv[])
{
   srand(time(0));
   initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

   Game game;

   SDL_Event e;
   clock_t startTime =SDL_GetTicks();
   int timer =0, delay =200;
   while (game.isRunning())
   {///game loop///
      ////event and data stat////
      while (SDL_PollEvent(&e)) {
         UserInput input = interpretEvent(e);
         game.handleInput(input);
      }
      ////setup timer////
      clock_t endTime =SDL_GetTicks();
      timer =endTime -startTime;
      if (timer >delay) {
         startTime =endTime;//reset timer
      }
         game.processing();
      renderGame(game);
      SDL_Delay(1);
   ///end game loop///
   }

   quitSDL(window, renderer);
   return 0;
}

SDL_Rect setRect(int x, int y, int w, int h){
   SDL_Rect res;
   res.x =x; res.y =y; res.w =w; res.h =h;
   return res;
}
void draw(SDL_Texture* texture, int x, int y) {
   SDL_Rect dst;
   dst.x =x; dst.y =y;
   SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
   SDL_RenderCopy(renderer, texture, NULL, &dst);
}
void draw(SDL_Texture* texture, SDL_Rect src, int x, int y) {
   SDL_Rect dst;
   dst.x =x; dst.y =y; dst.w =src.w; dst.h =src.h;
   SDL_RenderCopy(renderer, texture, &src, &dst);
}

   ////calculate point
      //0x value
      //0y value
UserInput interpretEvent(SDL_Event e) {
   if (e.type ==SDL_KEYDOWN)
      switch (e.key.keysym.sym) {
         case SDLK_q: return KEY_EXIT; break;
         case SDLK_DOWN: return KEY_DOWN; break;
         case SDLK_LEFT: return KEY_LEFT; break;
         case SDLK_RIGHT: return KEY_RIGHT; break;
         default: break;
      }
   if (e.type ==SDL_KEYUP) return NO_INPUT;
   if (e.type ==SDL_QUIT) return KEY_EXIT;
   return NO_INPUT;
}
void drawPixel(int color, int id_x, int id_y){
   static SDL_Texture* tiles =loadTexture("tiles.png", renderer);
   SDL_Rect src =setRect(18 *color, 0, 18, 18);
   draw(tiles, src, 18 *id_x, 18 *id_y);
}
void renderGame(const Game& game) {
   SDL_RenderClear(renderer);
   const vector< vector<int>>& board =game.getBoard();
   for (int i =0; i <10; i++)
   for (int j =0; j <20; j++)
      if (board[i][j] !=-1)
         drawPixel(board[i][j], i ,j);
   SDL_RenderPresent(renderer);
}
