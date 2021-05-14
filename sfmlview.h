#ifndef sfmlview_h
#define sfmlview_h

#include <SFML/Graphics.hpp>

#include "ship.h"
#include "board.h"
#include "green.h"

class Sfmlview {
    sf::RectangleShape square;
    Ship &player;
    Board &bullet;
    Green &enemy;
public:
    Sfmlview (Ship &player, Board &bullet, Green &enemy);
    void drawOnWindow (sf::RenderWindow & win);
};

#endif //sfmlview_h
