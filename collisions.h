#ifndef collisions_h
#define collisions_h

#include "board.h"
#include "green.h"
#include "ship.h"

class Collisions {
    Ship &player;
    Board &bullet;
    Green &enemy;
public:
    Collisions(Ship &player, Board &bullet, Green &enemy);
    void detector();
};

#endif //collisions_h
