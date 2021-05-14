#include "sfmlview.h"
#include "ship.h"
#include "green.h"
#include "board.h"

#include <iostream>
#include <string>

Sfmlview::Sfmlview(Ship &player, Board &bullet, Green &enemy) : player(player), bullet(bullet), enemy(enemy) {
    square.setSize(sf::Vector2f(20, 20));
}

void Sfmlview::drawOnWindow(sf::RenderWindow & win) {

        for (int row = 0; row < 80; row++) {
            for (int col = 0; col < 80; col++) {
                if (row == player.getxpos() && col == player.getypos()) {
                    if (player.is_alive()) {
                        square.setFillColor(sf::Color::Blue);
                        square.setPosition(row * 10, col*10);
                        win.draw(square);
                        square.setPosition((row + 2) * 10, col*10);
                        win.draw(square);
                        square.setPosition((row - 2) * 10, col*10);
                        win.draw(square);
                        square.setPosition(row * 10, (col-2)*10);
                        win.draw(square);
                    }
                }
            }
        }

        for (int row = 0; row < 80; row++) {
            for (int col = 0; col < 80; col++) {
                for (int items = 0; items < enemy.getenemys(); items++) {
                    if (row == enemy.getxpos(items) && col == enemy.getypos(items)) {
                        square.setFillColor(sf::Color::Red);
                        square.setPosition(row * 10, col*10);
                        win.draw(square);
                        square.setPosition((row+2) * 10, col*10);
                        win.draw(square);
                        square.setPosition((row-2) * 10, col*10);
                        win.draw(square);
                        square.setPosition((row-2) * 10, (col+2)*10);
                        win.draw(square);
                        square.setPosition((row+2) * 10, (col+2)*10);
                        win.draw(square);
                    }
                }
            }
        }
        for (int row = 0; row < 80; row++) {
            for (int col = 0; col < 80; col++) {
                for (int items = 0; items < bullet.getbullets(); items++) {
                    if (row ==  bullet.getxpos(items) && col == bullet.getypos(items)) {
                        if (bullet.gettype(items) == 'w') {
                            square.setFillColor(sf::Color::White);
                        } else if (bullet.gettype(items) == 'g') {
                            square.setFillColor(sf::Color::Green);
                        } else if (bullet.gettype(items) == 'r') {
                            square.setFillColor(sf::Color::Red);
                        } else {
                            square.setFillColor(sf::Color::Blue);
                        }
                        square.setPosition(row * 10, col * 10);
                        win.draw(square);
                    }
                }
            }
        }

        sf::Font font;
        if (!font.loadFromFile("./VeraSe.ttf")) {
            std::cout << "Error";
        }

        sf::Text text;
        text.setFont(font);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(2);
        text.setCharacterSize(40);
        text.setPosition(15, 15);
        std::string s = std::to_string(player.gethealth());
        text.setString(s);
        win.draw(text);

        if (player.is_alive() == false) {
            text.setFont(font);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold);
            text.setOutlineColor(sf::Color::White);
            text.setOutlineThickness(2);
            text.setCharacterSize(40);
            text.setPosition(320, 380);
            text.setString("You lost!");
            win.draw(text);
        }

        if (enemy.getenemys() == 0) {
            text.setFont(font);
            text.setFillColor(sf::Color::Green);
            text.setStyle(sf::Text::Bold);
            text.setOutlineColor(sf::Color::White);
            text.setOutlineThickness(2);
            text.setCharacterSize(40);
            text.setPosition(320, 380);
            text.setString("You won!");
            win.draw(text);
        }
}
