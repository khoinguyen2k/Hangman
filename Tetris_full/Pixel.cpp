#include "Pixel.h"
#include "Game.h"

Pixel::Pixel(Game* _game): position(0, 0), game(_game),
   direction(NO_DIR), color(0) { }

Direction Pixel::changeDirection(UserInput input) {
   switch (input) {
    case NO_INPUT: return NO_DIR; break;
    case KEY_LEFT:  return LEFT ; break;
    case KEY_RIGHT: return RIGHT ; break;
    case KEY_DOWN:  return DOWN ; break;
    default: return direction; break;
   }
}
void Pixel::handleInput(UserInput input){
   direction =changeDirection(input);
}
void Pixel::processing()
{
    Position newPosition = position.move(direction);
    game->changeCellId(position, -1);
    position = newPosition;
    game->changeCellId(position, color);
}
