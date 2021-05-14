#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>

#include "sfmlview.h"
#include "ship.h"
#include "green.h"
#include "board.h"
#include "collisions.h"
#include "menu.h"

int main() {

    srand(time(NULL));

    Menu menu;
    menu.display();

    constexpr int screen_width = 800;
	constexpr int screen_height = 800;
	sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "Space Invaders");
	win.setVerticalSyncEnabled(true);

    Ship player (menu.getspeed(), menu.getshootingspeed(), menu.gethealth());
    Board bullet;
    Green enemy;
    Collisions detect (player, bullet, enemy);
    Sfmlview view (player, bullet, enemy);

    for (int rows = 0; rows < menu.getenemysammount(); rows++) {
        for (int enemys = 0; enemys < 5; enemys++) {
            enemy.makeenemy(enemys, 10 + (enemys * 15), 10 + (rows * 15), 2);
        }
    }

    while (true) {
        int timer = 0, timer2 = 0;
        while(win.isOpen()) {
		    sf::Event event;
		    while(win.pollEvent(event)) {
			    if (event.type == sf::Event::Closed) {
				    win.close();
			    }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			        player.move(-player.getspeed(), 0);
		        }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			        player.move(player.getspeed(), 0);
		        }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			        player.move(0, -player.getspeed());
		        }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			        player.move(0, player.getspeed());
		        }
                if (player.is_fired() == false) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        player.fire(true);
                        timer = 0;
                        bullet.fired(player.getxpos(), player.getypos()-4, 0, -1, 2, 'w');
                        if (menu.getoption() == 2) {
                            bullet.fired(player.getxpos(), player.getypos()-4, 1, -1, 2, 'w');
                            bullet.fired(player.getxpos(), player.getypos()-4, -1, -1, 2, 'w');
                        }
		            }
                }
                if (enemy.getenemys() == 0 || player.is_alive() == false) {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                        return 0;
                    }
                }
		    }

            if (player.is_alive()) {
                bullet.move();
                enemy.moveenemys(timer);
                detect.detector();

                if (timer > player.getshootspeed()) {
                    player.fire(false);
                }
                if (timer2 > player.getshootspeed()) {
                    for (int shots = 0; shots < rand() % enemy.getenemys(); shots++) {
                        int temp = rand() % enemy.getenemys();
                        bullet.fired(enemy.getxpos(temp), enemy.getypos(temp), -1 + (rand() % 3), 1, 1, 'g');
                    }
                    timer2 = 0;
                }
            }

		    win.clear(sf::Color::Black);
            view.drawOnWindow(win);
            win.display();
            timer++;
            timer2++;
        }
    }
    return 0;
}
