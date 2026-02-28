#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Snake.h"

class Game
{
public:
	Game(sf::RenderWindow& window);
	void Go();
	void Movement(); //movement function to store all those keys
	void Draw();
	sf::RenderWindow& window;
	std::mt19937 rng;
	sf::Clock moveClock;
	sf::Time moveDelay = sf::seconds(0.2f); //0.2 seconds per move, 5 move/sec

	Snake snake;
	Location loc;
	Board board;
	sf::Color color;

	Location delta_loc = { 0, 0 }; //for the movement keys

	
};