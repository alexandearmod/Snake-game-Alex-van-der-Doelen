#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include <random>

class Food
{
public:
	std::mt19937 rng; //rng for the food
	Location loc{};
	sf::Color color;
	void draw(sf::RenderWindow& window, Board& board); //draw the food
	bool isEaten = false;

	int x{};
	int y{};

};