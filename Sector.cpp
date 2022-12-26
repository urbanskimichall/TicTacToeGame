#include "Sector.h"

Sector::Sector(float xCord, float yCord, sf::Sprite s)
{
    xCordinate = xCord;
    yCordinate = yCord;
    sprite = s;
    sprite.setPosition(xCord, yCord);
}

bool Sector::isSectorClicked(float x, float y)
{
    if (xCordinate < x && x < xCordinate + 200 && yCordinate < y && y < yCordinate + 200)
    {
        return true;
    }
    else return false;
}

void Sector::setImagePosition()
{
    sprite.setPosition(xCordinate, yCordinate);
}
