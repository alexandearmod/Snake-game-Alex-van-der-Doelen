#include "Game.h"
#include <random>
#include <SFML/Graphics.hpp>
#include <sstream>
/// notes
/// add game over screen
/// 
///
///
/// if not inside board, set game over
Game::Game(sf::RenderWindow& window) //constructer
	:
	window(window), //store a reference to window
	rng(std::random_device{}()), //initialize random generator
	board(), //initialize the board
	snake({ 10,10 }) //initialize snake and starting location

	
	
{

void Game::Go()
{
	if (moveClock.getElapsedTime() >= moveDelay)
	{
		Movement();
		moveClock.restart(); //a timer to prevent the snake from moving at incredible speeds, instead it can only move by a few frames(as set in game.h, 0,2 for each move = 5 moves/sec
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
			delta_loc = { 1, 0 };
		}
		

		

		if (moveClock.getElapsedTime() >= moveDelay)
		{
			if (!board.IsInside(snake.NextHeadLocation(delta_loc)))
			{
				GameOver = true;
			}
			else
			{
				snake.Move(delta_loc);
			}
			moveClock.restart();
		}






}

void Game::Draw()
{
	snake.Draw(window, board); //draws the snake
	food.draw(window, board);	// draws the food

	
	sf::Text text(font);
	
	if (GameOver)
	{
		sf::RectangleShape gameoverbg(sf::Vector2f(800, 600)); //fill the entire background with black transparacy when the game is over
		gameoverbg.setFillColor(sf::Color(0, 0, 0, 100)); //https://www.youtube.com/watch?v=U0k15TMhW9w

		sf::Text GameOverText(font); //set text
		GameOverText.setString("Game Over");
		GameOverText.setCharacterSize(60);
		GameOverText.setPosition({ 250.f, 250.f });
		
		sf::Text scoreText(font);
		scoreText.setCharacterSize(24);
		std::ostringstream output;
		output << "Score: " << score;
		scoreText.setString(output.str());


		window.draw(gameoverbg);
		window.draw(GameOverText);
		window.draw(scoreText);

	}
}

void Game::TestCollision()
{

	if ((snake.size[0].loc.x == food.loc.x) && (snake.size[0].loc.y == food.loc.y))
		//I had trouble finding a good way to get a collision system going, but ended up stumbling across another persons code, who did not have the same question, but in their code I found their collision system to be-
		//-exactly what I needed.
	//https://stackoverflow.com/questions/60099274/how-can-i-define-a-game-over-in-snake-game-using-sfml
		//where if the snake's head collides with the x and the y of the food, you set a new position. Instead I set food.iseaten to true and set the position with <random>.
	{
		food.isEaten = true;
	}
	if (food.isEaten)
	{
		snake.Grow(); //grow the snake
		std::uniform_int_distribution<int> xDist(0, board.width - 1);
		std::uniform_int_distribution<int> yDist(0, board.height - 1);

		food.loc.x = xDist(rng); //set new location 
		food.loc.y = yDist(rng);

		score++; //increase score
		food.isEaten = false; //reset food
	}
	//increase the speed with each 5 scores
	if (score >= 5)
	{
		moveDelay = sf::seconds(0.18f);
	}
	if (score >= 10)
	{
		moveDelay = sf::seconds(0.016f);
	}
	if (score >= 15)
	{
		moveDelay = sf::seconds(0.014f);
	}
	if (score >= 20)
	{
		moveDelay = sf::seconds(0.012f);
	}


}


