#include <iostream>

#include <zconf.h>
#include <synchapi.h>

#include "TicTacToeGame.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 600), "TicTacToeGame");
    TicTacToeGame ticTacToeGame;
    ticTacToeGame.initGameBoard();
    ticTacToeGame.initPredefinedSectors();
    ticTacToeGame.initSectors();

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                ticTacToeGame.runGame(event, window);

                std::cout << "clicked " << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
            }
        }
        window.clear();
        ticTacToeGame.drawGameBoard(window);
        window.display();
    }
    return 0;
}
