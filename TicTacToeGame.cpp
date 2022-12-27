#include "TicTacToeGame.h"

void TicTacToeGame::initGameBoard() {

    texture.loadFromFile("../Pictures/emptyField.jpg");
    texture1.loadFromFile("../Pictures/circle.jpg");
    texture2.loadFromFile("../Pictures/cross.jpg");
    texture3.loadFromFile("../Pictures/winnerCross.jpg");
    texture4.loadFromFile("../Pictures/winnerCircle.jpg");

    sprite.setTexture(texture);
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite3.setTexture(texture3);
    sprite4.setTexture(texture4);
}

void TicTacToeGame::initPredefinedSectors() {

    predefinedSectors.emplace_back(0, 0, sprite);
    predefinedSectors.emplace_back(0, 0, sprite1);
    predefinedSectors.emplace_back(0, 0, sprite2);
    predefinedSectors.emplace_back(0, 0, sprite3);
    predefinedSectors.emplace_back(0, 0, sprite4);
}

void TicTacToeGame::initSectors() {

    sectors[0] = {0, 0, sprite};
    sectors[1] = {200, 0, sprite};
    sectors[2] = {400, 0, sprite};
    sectors[3] = {0, 200, sprite};
    sectors[4] = {200, 200, sprite};
    sectors[5] = {400, 200, sprite};
    sectors[6] = {0, 400, sprite};
    sectors[7] = {200, 400, sprite};
    sectors[8] = {400, 400, sprite};
}

void TicTacToeGame::runGame(sf::Event &event, sf::RenderWindow& window) {

    for (int i{0}; i < sectors.size(); i++)
    {
        if (sectors[i].isSectorClicked(event.mouseButton.x, event.mouseButton.y))
        {
            if (sectors[i].state == SectorState::EMPTY)
            {
                selectXOturn(i);
            }

            sectors[i].setImagePosition();

            std::cout << "doesntwork " << i << std::endl;
        }
        for (int j = 0; j < indexesForWinner.size(); ++j)
        {
            if (isCircleWin(j))
            {
                circleWin(i,j);
                drawGameBoard(window);
                playAgain(window, event);
                initPredefinedSectors();
                initSectors();
            }
            else if (isCrossWin(j))
            {
                crossWin(i,j);
                drawGameBoard(window);
                playAgain(window, event);
                initPredefinedSectors();
                initSectors();
            }
        }
    }
}

void TicTacToeGame::drawGameBoard(sf::RenderWindow &window) {

    for (int i = 0; i < sectors.size(); i++) {
        window.draw(sectors[i].sprite);
    }
}

void TicTacToeGame::selectXOturn(int i) {

    if (isPlayerXturn)
    {
        predefinedSectors[2].xCordinate = sectors[i].xCordinate;
        predefinedSectors[2].yCordinate = sectors[i].yCordinate;
        sectors[i] = predefinedSectors[2];
        sectors[i].state = SectorState::CROSS;
        isPlayerXturn = false;
    } else
    {
        predefinedSectors[1].xCordinate = sectors[i].xCordinate;
        predefinedSectors[1].yCordinate = sectors[i].yCordinate;
        sectors[i] = predefinedSectors[1];
        sectors[i].state = SectorState::CIRCLE;
        isPlayerXturn = true;
    }

}

void TicTacToeGame::circleWin(int i, int j) {

    isWinner = true;
    predefinedSectors[4].xCordinate = sectors[i].xCordinate;
    predefinedSectors[4].yCordinate = sectors[i].yCordinate;
    sectors[i] = predefinedSectors[4];

    sectors[indexesForWinner[j][0]].sprite = sprite4;
    sectors[indexesForWinner[j][0]].setImagePosition();
    sectors[indexesForWinner[j][1]].sprite = sprite4;
    sectors[indexesForWinner[j][1]].setImagePosition();
    sectors[indexesForWinner[j][2]].sprite = sprite4;
    sectors[indexesForWinner[j][2]].setImagePosition();
    std::cout << "Circle win " << std::endl;

}

void TicTacToeGame::crossWin(int i, int j) {
    isWinner = true;
    predefinedSectors[3].xCordinate = sectors[i].xCordinate;
    predefinedSectors[3].yCordinate = sectors[i].yCordinate;
    sectors[i] = predefinedSectors[3];

    sectors[indexesForWinner[j][0]].sprite = sprite3;
    sectors[indexesForWinner[j][0]].setImagePosition();
    sectors[indexesForWinner[j][1]].sprite = sprite3;
    sectors[indexesForWinner[j][1]].setImagePosition();
    sectors[indexesForWinner[j][2]].sprite = sprite3;
    sectors[indexesForWinner[j][2]].setImagePosition();
    std::cout << "Cross win " << std::endl;

}

bool TicTacToeGame::isCrossWin(int j) {

    return sectors[indexesForWinner[j][0]].state == SectorState::CROSS &&
           sectors[indexesForWinner[j][1]].state == SectorState::CROSS &&
           sectors[indexesForWinner[j][2]].state == SectorState::CROSS;
}

bool TicTacToeGame::isCircleWin(int j) {
    return sectors[indexesForWinner[j][0]].state == SectorState::CIRCLE &&
           sectors[indexesForWinner[j][1]].state == SectorState::CIRCLE &&
           sectors[indexesForWinner[j][2]].state == SectorState::CIRCLE;
}

void TicTacToeGame::playAgain(sf::RenderWindow& window, sf::Event &event) {

    sf::RectangleShape playAgainButton;
    playAgainButton.setSize({400, 300});
    playAgainButton.setFillColor({0,255,0});
    playAgainButton.setPosition(100, 150);

    window.draw(playAgainButton);
    window.display();
    bool isClicked{false};
    while (window.isOpen())
    {
        while (window.pollEvent(event)) {
            std::cout << "tuuu";
            if (event.type == sf::Event::MouseButtonPressed &&
                (event.mouseButton.x>=100 && event.mouseButton.x<=500 && event.mouseButton.y>=150 && event.mouseButton.y<=450) )
            {
                isClicked = true;
            }
        }
        if(isClicked)
        {
            break;
        }
    }

}
