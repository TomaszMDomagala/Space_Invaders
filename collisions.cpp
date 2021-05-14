#include "collisions.h"

Collisions::Collisions(Ship &player, Board &bullet, Green &enemy) : player(player), bullet(bullet), enemy(enemy) {

}

void Collisions::detector() {
    if (player.getxpos() > 76) {
        player.getdamage(2);
        player.move(-10, 0);
    }
    if (player.getxpos() < 2) {
        player.getdamage(2);
        player.move(10, 0);
    }
    if (player.getypos() < 2) {
        player.getdamage(2);
        player.move(0, 10);
    }
    if (player.getypos() > 78) {
        player.getdamage(2);
        player.move(0, -10);
    }

    for (int i = 0; i < enemy.getenemys(); i++) {
        if (player.getypos() == enemy.getypos(i)) {
            if (player.getxpos() == enemy.getxpos(i)) {
                player.getdamage(2);
                player.move(rand() % 6, rand() % 6);
            }
        }
    }

    for (int i = 0; i < bullet.getbullets(); i++) {
        if (player.getypos() - 2 <= bullet.getypos(i) && player.getypos() >= bullet.getypos(i)) {
            if (player.getxpos() -2 <= bullet.getxpos(i) && player.getxpos() + 2 >= bullet.getxpos(i)) {
                player.getdamage(2);
                bullet.removebullet(i);
            }
        }
    }

    for (int enemys = 0; enemys < enemy.getenemys(); enemys++) {
        for (int bullets = 0; bullets < bullet.getbullets(); bullets++) {
            if (bullet.gettype(bullets) == 'w') {
                if (enemy.getypos(enemys) <= bullet.getypos(bullets) && enemy.getypos(enemys) + 2 >= bullet.getypos(bullets)) {
                    if (enemy.getxpos(enemys) - 2 <= bullet.getxpos(bullets) && enemy.getxpos(enemys) + 2 >= bullet.getxpos(bullets)) {
                        enemy.getdamage(enemys, 2);
                        bullet.removebullet(bullets);
                    }
                }
            }
        }
    }

}
