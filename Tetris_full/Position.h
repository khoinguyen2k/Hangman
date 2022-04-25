#ifndef POSITION_H
#define POSITION_H

enum Direction { NO_DIR = 0, DOWN, LEFT, RIGHT };
struct Position{
   int x, y;
   Position(int _x =0, int _y =0) {
      x =_x; y =_y;
   }
   bool isInsideBoard(Position top_left, Position down_right) {
      return (x >=top_left.x && x <down_right.x && y >=top_left.y && y <down_right.y);
   }
   Position move(Direction d)
   {
      const int dx[] = {0,0,-1,1};
      const int dy[] = {0,1,0,0};
      Position pos(x +dx[d], y +dy[d]);
      if (pos.isInsideBoard(Position(0, 0),  Position(10, 20)) )
         return pos;
      return Position(x, y);
   }
};

#endif
