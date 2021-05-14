#include "ship.h"

#include <iostream>

Ship::Ship (int speed, int shoot_speed, int health) {

    this -> speed = speed;
    this -> shoot_speed = shoot_speed;
    this -> health = health;

    pos.xpos = 40;
    pos.ypos = 70;
}

int Ship::getxpos () {
    return pos.xpos;
}

int Ship::getypos () {
    return pos.ypos;
}

int Ship::getscore () {
    return score;
}

int Ship::getspeed () {
    return speed;
}

int Ship::getstate () {
    return is_crashed;
}

int Ship::getshootspeed () {
    return shoot_speed;
}

void Ship::move (int x, int y) {

    if (x != 0 && y != 0) {
        std::cout << "Movement error";
    }

    if (x != 0) {
        pos.xpos += x;
    } else if (y != 0) {
        pos.ypos += y;
    }
}

void Ship::fire (bool state) {
    if (state == true) {
        recently_fired = true;
    } else {
        recently_fired = false;
    }
}

bool Ship::is_ship (int x, int y) {

    if (x == pos.xpos && y == pos.ypos) {
        return true;
    } else {
        return false;
    }
}

void Ship::getdamage (int damage) {
    health -= damage;
}

bool Ship::is_alive() {
    if (health > 0) {
        return true;
    } else {
        return false;
    }
}

bool Ship::is_fired() {
    return recently_fired;
}

int Ship::gethealth() {
    return health;
}
