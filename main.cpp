#include <iostream>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#define ll long long

using namespace std;
struct Point{
   int x, y;
   Point(int _x =0, int _y =0){
      x =_x;
      y =_y;
   }
};

const int SCREEN_WIDTH =480;
const int SCREEN_HEIGHT =640;
const string WINDOW_TITLE ="Testt!!";

const Point START_CORNER(28, 31);
const Point ROOT(0, 0);

const int MAX_COLOR_NUM =8;
const int PIXEL_SIZE =18;
const int NUM_ROW =20;
const int NUM_COLUMN =10;

static SDL_Window* window;
static SDL_Renderer* renderer;

void draw(SDL_Texture* texture, int x, int y);

const int piece_id[7][4]={
      1,3,5,7, // I
      2,4,5,7, // Z
      3,5,4,6, // S
      3,5,4,7, // T
      2,3,5,7, // L
      3,5,7,6, // J
      2,3,4,5, // O
};
class Piece{
   SDL_Texture* texture;
   int type;
   int color;
   Point pixel_corner[4];
public:

};
int main(int argc, char* agrv[])
{
   srand(time(0));
   initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

   Piece piece;
   ////display background////
   ////display tiles///
   ////display frame///

   bool quit =false;
   clock_t time_1 =SDL_GetTicks();
   while (!quit)
   {///game loop///
      ////event and data stat////
      SDL_Event e;
      int timer =0, delay =200;

      while (SDL_PollEvent(&e) )
      {
         if (e.type ==SDL_QUIT) break;

      }
      ////setup timer////
      clock_t time_2 =SDL_GetTicks();
      timer =time_2 -time_1;

      if (timer >delay) {
         time_1 =time_2;//reset timer
      }

      ////calculate point
         //0x value
         //0y value

      ///draw img with new stat info num

   }///end game loop///

   //free SDL
   quitSDL(window, renderer);
   return 0;
}

void draw(SDL_Texture* texture, int x, int y)
{
   SDL_Rect dst;
   dst.x =x;
   dst.y =y;
   SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
   SDL_RenderCopy(renderer, texture, NULL, &dst);
}
