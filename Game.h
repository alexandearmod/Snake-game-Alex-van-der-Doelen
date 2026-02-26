#pragma once
#include <SFML/Graphics.hpp>
#include <random>

class Game
{
public:
	Game(sf::RenderWindow& window);
	void Go();
	sf::RenderWindow& window;
	std::mt19937 rng;
	sf::Color RandomColor();
};