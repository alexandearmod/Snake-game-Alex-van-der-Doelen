#include "Food.h"



void Food::draw(sf::RenderWindow& window, Board& board)
{
	board.DrawCell(window, loc, color);
}
