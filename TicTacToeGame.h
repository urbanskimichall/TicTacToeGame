#ifndef SECTOR_H_TICTACTOEGAME_H
#define SECTOR_H_TICTACTOEGAME_H
#include <SFML/Graphics.hpp>
#include "Sector.h"
#include <iostream>


class TicTacToeGame {
public:
    void initGameBoard();
    void initPredefinedSectors();
    void initSectors();
    void runGame(sf::Event& event, sf::RenderWindow& window);
    void drawGameBoard(sf::RenderWindow& window);

private:
    void selectXOturn(int i);
    void circleWin(int i, int j);
    void crossWin(int i, int j);
    bool isCrossWin(int j);
    bool isCircleWin(int j);
    void playAgain(sf::RenderWindow& window, sf::Event &event);

    sf::Texture texture;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Texture texture3;
    sf::Texture texture4;

    sf::Sprite sprite;
    sf::Sprite sprite1;
    sf::Sprite sprite2;
    sf::Sprite sprite3;
    sf::Sprite sprite4;

    std::vector<std::vector<int>> indexesForWinner
            {{0, 1, 2},
             {3, 4, 5},
             {6, 7, 8},
             {0, 3, 6},
             {1, 4, 7},
             {2, 5, 8},
             {0, 4, 8},
             {2, 4, 6}};

    std::vector<Sector> predefinedSectors;
    std::map<int, Sector> sectors;

    bool isPlayerXturn{true};
    bool isWinner{false};
};
#endif //SECTOR_H_TICTACTOEGAME_H
