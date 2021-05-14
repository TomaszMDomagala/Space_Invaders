#ifndef ship_h
#define ship_h

struct position {
    int xpos;
    int ypos;
};

class Ship {
    position pos;
    bool is_crashed = false;
    int speed;
    int shoot_speed;
    bool recently_fired = false;
    int health;
    int score = 0; //forgot
public:
    Ship (int speed, int shoot_speed, int health);
    int getxpos ();
    int getypos ();
    int getscore ();
    int getspeed ();
    int getstate ();
    int getshootspeed (); //forgot
    void move (int x, int y);
    void fire (bool state);
    bool is_ship (int x, int y); // forgot about parameters
    void getdamage (int damage); // forgot about parameters
    bool is_alive(); // new function
    bool is_fired(); // new function
    int gethealth(); //new function
};

#endif //ship_h
