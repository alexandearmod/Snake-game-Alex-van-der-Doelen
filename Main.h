#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Location.h"
#include <random>
#include "Snake.h"
class Main
{

public:
	Location loc;
	std::mt19937 rng;
	sf::Color color = sf::Color::Transparent;
	Snake snake;
};

