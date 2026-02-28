#include "Game.h"
#include <random>
Game::Game(sf::RenderWindow& window)
	:
	window(window), //store a reference to window
	rng(std::random_device{}()), //initializer random generator
	board(),
	snake({ 10,10 }) //initialize snake and location

{
}

void Game::Go()
{
	

	if (moveClock.getElapsedTime() >= moveDelay)
	{
		Movement();
		moveClock.restart();
	}
	Draw();
}

void Game::Movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) //https://www.sfml-dev.org/tutorials/3.0/window/inputs/#introduction
	{
		delta_loc = { 0, -1 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
	{
		delta_loc = { -1, 0 };
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		delta_loc = { 0, 1 };
	}
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		delta_loc = { 1, 0};
	}

	snake.Move(delta_loc);

}

void Game::Draw()
{
	snake.Draw(window, board);
}


