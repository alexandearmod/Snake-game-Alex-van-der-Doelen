#include "Board.h"
#include "Main.h"

void Board::DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color)
{
    sf::RectangleShape rectangle(
        sf::Vector2f((float)dimension, (float)dimension)
    );

    rectangle.setFillColor(color);
    rectangle.setPosition({ loc.x * dimension, loc.y * dimension});

    window.draw(rectangle);

   
 
}