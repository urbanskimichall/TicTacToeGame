#ifndef TIKTAKTOE_SECTOR_H
#define TIKTAKTOE_SECTOR_H

#include <SFML/Graphics/Sprite.hpp>
#include "SectorState.h"

class Sector
{
public:
    Sector(){}
    Sector(float xCord, float yCord, sf::Sprite s);
    float xCordinate{0.0};
    float yCordinate{0.0};
    sf::Sprite sprite;

    bool isSectorClicked(float x, float y);
    void setImagePosition();

    SectorState state{SectorState::EMPTY};
};
#endif //TIKTAKTOE_SECTOR_H
