#include "Snake.h"

Snake::Snake(const Location& loc)
{
	size[0].LocationHead(loc);
}

void Snake::Move(const Location& delta_loc)
{
	for (int i = currentSize - 1; i > 0; --i) //find the end of the snake (besides the head)
	{
		size[i].Follow(size[i - 1]); //follow the segment that is in front of
	}
	size[0].Move(delta_loc); //move the head of the snake (which the player controls) by delta loc.
	//I use delta location because it moves the snake by frame, not by player input. This will keep the snake constantly moving.
}




void Snake::Grow()
{
	if (currentSize < maxCurrentSize) //if the current size is smaller than the maximum size
	{
		++currentSize; //increase the size (when you collect)
	}
}

void Snake::Draw(sf::RenderWindow& window, Location loc, sf::Color color) //draw the snake, and the segments one by one once they're collected and added
{
	for (int i = 0; i < currentSize; ++i)
	{
		size[i].Draw(window, loc, color);
	}
}
