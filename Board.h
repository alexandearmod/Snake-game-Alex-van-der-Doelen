#pragma once
#include "Location.h"
#include <SFML/Graphics.hpp>
class Board
{
public:
	

	void DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color);

	float dimension = 20; //boxes of grid will be 20x20
	
	int width = 30;;
	int height = 30;
	sf::Color color = sf::Color::White;
	
	


};