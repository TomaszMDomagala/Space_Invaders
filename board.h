#ifndef board_h
#define board_h

#include <string>
#include <vector>

struct bullet {
    int xpos;
    int ypos;
    int xdir;
    int ydir;
    int speed;
    char colour; //changed from string
};

class Board {
    std::vector<bullet> bullets;
public:
    void move(); //added function
    void fired(int xp, int yp, int xd, int yd, int spe, char co);
    int getxpos(int id);
    int getypos(int id);
    int getbullets(); //added function
    void removebullet(int id);
    char gettype(int id);
};

#endif //board_h
