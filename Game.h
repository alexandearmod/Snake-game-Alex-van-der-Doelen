#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Snake.h"
#include "Food.h"
#include "FoodLocation.h"
#include <SFML/Audio.hpp>
class Game
{
public:
	Game( sf::RenderWindow & window );
	void Go();
	void Movement(); //movement function to store all those keys
	void Draw();
	void TestCollision();
	void Sound();
	void Restart();
	sf::Font font;
	bool GameOver = false;
	
	sf::SoundBuffer collectBuffer;
	sf::Sound collectSound;

	int score = 0;
	sf::RenderWindow& window;
	std::mt19937 rng;
	sf::Clock moveClock;
	sf::Time moveDelay = sf::seconds(0.2f); //0.2 seconds per move, 5 move/sec

	Snake snake; 
	Food food;
	Location loc;
	Board board;
	sf::Color color;

	Location delta_loc = { 0, 0 }; //for the movement keys

	
	
};