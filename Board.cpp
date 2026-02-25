#include "Board.h"
#include "Main.h"


void Board::DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color)
{
    sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setFillColor(color);
    rectangle.setPosition({ loc.x, loc.y });

    window.draw(rectangle);
}