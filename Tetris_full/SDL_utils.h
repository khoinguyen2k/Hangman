// SDL_utils.h
#ifndef SDL_UTILS_H
#define SDL_UTILS_H
using namespace std;

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer,
   const int &SCREEN_WIDTH, const int &SCREEN_HEIGHT, const string &WINDOW_TITLE);
void logSDLError(ostream& os, const string &msg, bool fatal =false);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();
//SDL_image
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);
#endif
