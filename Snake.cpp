#include "Snake.h"
#include "Location.h"

Snake::Snake(const Location& loc)
{
	size[0].LocationHead(loc);
	currentSize = 1;
}
//transform
void Snake::Transform::LocationHead(const Location& find_loc)
{
	loc = find_loc;
	color = Snake::headcolor; //set the color of the head, color is set in snake.h
}

void Snake::Transform::Move(const Location& delta_loc)
{
	loc.increase(delta_loc); //move by square (delta)
}

void Snake::Transform::Body()
{
	color = Snake::bodycolor; //set body color of the snake.
}

void Snake::Transform::Follow(const Transform& follow)
{
	loc = follow.loc; //the last segment will follow the next
}


void Snake::Transform::Draw(sf::RenderWindow& window)
{
	board.DrawCell(window, loc, color);
}

////


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



void Snake::Draw(sf::RenderWindow& window, Board& board)//draw the snake, and the segments one by one once they're collected and added
{
	for (int i = 0; i < currentSize; ++i)
	{
		board.DrawCell(window, size[i].loc, size[i].color);
	}
}
