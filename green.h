#ifndef green_h
#define green_h

#include <vector>
#include <cmath>

struct positions {
    int xpos;
    int ypos;
    int xdir;
    int ydir;
    int health;
};

class Green {
    std::vector<positions> enemys;
public:
    void makeenemy(int id, int xp, int yp, int hp);
    int getxpos (int id);
    int getypos (int id);
    void getdamage (int id, int damage);
    int getenemys();
    void moveenemys(int timer);
};

#endif //green_h
