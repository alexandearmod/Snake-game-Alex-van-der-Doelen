#pragma once
#include "Location.h"
#include <SFML/Graphics.hpp>
class Board
{
public:
	

	void DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color);

	int dimension = 20; //boxes of grid will be 20x20
	bool IsInside(const Location& loc);

	int width = 800 / dimension;
	int height = 600 / dimension;
	sf::Color color = sf::Color::White;
	
	


};