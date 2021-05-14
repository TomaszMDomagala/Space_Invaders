#include "green.h"

int Green::getxpos (int id) {
    return enemys[id].xpos;
}

int Green::getypos (int id) {
    return enemys[id].ypos;
}

void Green::getdamage (int id, int damage) {
    enemys.at(id).health -= damage;
    if (enemys.at(id).health < 0) {
        enemys.erase(enemys.begin() + id);
    }
}

void Green::makeenemy(int id, int xp, int yp, int hp) {
    positions enemy;
    enemy.xpos = xp;
    enemy.ypos = yp;
    enemy.xdir = rand() % 2;
    enemy.ydir = rand() % 2;
    enemy.health = hp;
    enemys.push_back(enemy);
}

int Green::getenemys() {
    return enemys.size();
}

void Green::moveenemys(int timer) {

    if (timer == 15 || timer == 7) {
        for (int i = 0; i < enemys.size(); i++) {
            if (rand() % 4 < 3) {
                enemys.at(i).xpos += enemys.at(i).xdir;
                enemys.at(i).xdir *= -1;
            }
            if (rand() % 4 < 3) {
                enemys.at(i).ypos += enemys.at(i).ydir;
                enemys.at(i).ydir *= -1;
            }
        }
    }
}
