#ifndef menu_h
#define menu_h
#include <SFML/Graphics.hpp>

class Menu {
    const int menu_screen_height = 400;
    const int menu_screen_width = 400;
    int option = 0;
    int speed = 0;
    int health = 0;
    int enemys = 0;
    int shoot_speed = 0;
public:
    void display();
    void drawOnWindow (sf::RenderWindow & win);
    int getoption();
    int getspeed();
    int gethealth();
    int getenemysammount();
    int getshootingspeed();
};

#endif //menu_h
