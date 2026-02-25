#pragma once
#include "Location.h"
#include <SFML/Graphics.hpp>
class Board
{
	
public:
	void DrawCell(sf::RenderWindow& window, Location& loc, sf::Color color);


	static constexpr int dimension{ 20 }; //boxes of grid will be 20x20

	int width = 10;;
	int height = 10;
	sf::Color White;
	
private:

};