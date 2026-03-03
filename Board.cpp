#include "Board.h"
#include "Main.h"
#include "Location.h"
#include <SFML/Graphics.hpp>

void Board::DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color) //https://www.sfml-dev.org/tutorials/3.0/graphics/shape/#texture
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(static_cast<float>(dimension), static_cast<float>(dimension)));
    rectangle.setFillColor(color);
    rectangle.setPosition(sf::Vector2f(loc.x * static_cast<float>(dimension), loc.y * static_cast<float>(dimension)));
    rectangle.setOutlineColor(sf::Color::Black);
    rectangle.setOutlineThickness(2.f);
    window.draw(rectangle); //draw a rectangle (cell) on the board when it is called, at a given location
}
bool Board::IsInside(const Location& loc) //https://labex.io/tutorials/cpp-how-to-handle-boundary-condition-checks-420855
{
    return loc.x >= 0 && loc.x < width && loc.y >= 0 && loc.y < height; //checks if the snake is inside of the window, returns true/false.
}

