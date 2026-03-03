#pragma once

#include "resource.h"
#include <SFML/Graphics.hpp>
#include "Board.h"

class Snake
{

public:
	class Transform //parts of the snake
	{
	public:
		void LocationHead(const Location& loc);
		void Body();
		void Move(const Location& delta_loc);
		//make the tail follow the head of the snake
		void Follow(const Transform& follow);
		void Draw(sf::RenderWindow& window); //draw the body parts

		Location loc; //reference location and color to be able to use it
		sf::Color color;
		Board board;

	};

	
	Snake(const Location& loc);
	void Move(const Location& delta_loc);
	void Grow(); //grow the snake, which then uses follow to have the body part follow the next
	void Draw(sf::RenderWindow& window, Board& board); //draw the snake
	
	static constexpr sf::Color headcolor = sf::Color::Green;
	static constexpr sf::Color bodycolor = sf::Color::Blue;
	static constexpr int maxCurrentSize = 99; //maximum size of snake
	Transform size[maxCurrentSize];
	int currentSize = 1; //current size of snake
	//Array segments start at 0, so 0 will be the head of the snake.
};



