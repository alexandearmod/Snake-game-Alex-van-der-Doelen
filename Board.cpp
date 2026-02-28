#include "Board.h"
#include "Main.h"
#include "Location.h"
#include <SFML/Graphics.hpp>

void Board::DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(static_cast<float>(dimension), static_cast<float>(dimension)));
    rectangle.setFillColor(color);
    rectangle.setPosition(sf::Vector2f(loc.x * static_cast<float>(dimension), loc.y * static_cast<float>(dimension)));
    window.draw(rectangle);
}