#include "board.h"

#include <iostream>

void Board::move() {

    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].xdir == 1) {
            bullets[i].xpos += bullets[i].speed;
        }
        if (bullets[i].xdir == -1) {
            bullets[i].xpos -= bullets[i].speed;
        }
        if (bullets[i].ydir == 1) {
            bullets[i].ypos += bullets[i].speed;
        }
        if (bullets[i].ydir == -1) {
            bullets[i].ypos -= bullets[i].speed;
        }

        if (bullets[i].ypos > 80 || bullets[i].ypos < 0) {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void Board::fired(int xp, int yp, int xd, int yd, int spe, char co) {
    bullet a;
    a.xpos = xp;
    a.ypos = yp;
    a.xdir = xd;
    a.ydir = yd;
    a.speed = spe;
    a.colour = co;
    bullets.push_back(a);
}

int Board::getxpos(int id) {
    return bullets.at(id).xpos;
}

int Board::getypos(int id) {
    return bullets.at(id).ypos;
}

int Board::getbullets() {
    return bullets.size();
}

void Board::removebullet(int id) {
    bullets.erase(bullets.begin() + id);
}

char Board::gettype(int id) {
    return bullets.at(id).colour;
}
