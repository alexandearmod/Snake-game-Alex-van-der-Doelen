#include "Game.h"
#include <random>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>
/// notes
/// add border to screen
/// close border?
///
///obstacles
/// 
/// add sound with pickup
Game::Game(sf::RenderWindow& window) //constructer
	:
	window(window), //store a reference to window
	rng(std::random_device{}()), //initialize random generator
	board(), //initialize the board
	snake({ 10,10 }), //initialize snake and starting location
	collectBuffer(),
	collectSound(collectBuffer)   // construct sound with buffer

{
	std::uniform_int_distribution<int> xDist(0, board.width - 1);//the food can not spawn outside of the border
	std::uniform_int_distribution<int> yDist(0, board.height - 1); // - 1 so that it can not spawn on the border
	//https://stackoverflow.com/questions/21237905/how-do-i-generate-thread-safe-uniform-random-numbers
	if (font.openFromFile("fonts/EndFont.ttf")) //https://www.sfml-dev.org/tutorials/3.0/graphics/text/
		//font taken from https://www.dafont.com/
	
	if (collectBuffer.loadFromFile("fonts/collection.mp3")); //https://www.sfml-dev.org/tutorials/3.0/audio/sounds/#loading-and-playing-a-sound
	collectSound.setBuffer(collectBuffer);
		


	food.loc.x = xDist(rng);
	food.loc.y = yDist(rng); //draw the food at random coordinates for the first time
	food.color = sf::Color::Red;
}

void Game::Go()
{
	Draw();
	Movement();
	TestCollision();
}

void Game::Sound()
{
	collectSound.play();
}



void Game::Movement()
{
	
	if (!GameOver) //if not game over, you can control the snake
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) //https://www.sfml-dev.org/tutorials/3.0/window/inputs/#introduction
		{
			delta_loc = { 0, -1 };
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			delta_loc = { -1, 0 };
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			delta_loc = { 0, 1 };
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			delta_loc = { 1, 0 };
		}


		if (moveClock.getElapsedTime() >= moveDelay)
		{
			if (!board.IsInside(snake.NextHeadLocation(delta_loc))) //if you hit the border, game over
			{
				GameOver = true;
			}
			else
			{
				snake.Move(delta_loc); //and it will stop the movement if the game is over
			}
			moveClock.restart();
			}
		}

	if (GameOver) //if the game is over, press space to go again
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			Restart();
		}
		return;
	}
}

	




void Game::Draw()
{
	snake.Draw(window, board); //draws the snake
	food.draw(window, board);	// draws the food

	
	sf::Text text(font);
	sf::RectangleShape gameoverbg(sf::Vector2f(800, 600)); 
	gameoverbg.setFillColor(sf::Color(0, 0, 0, 100)); //https://www.youtube.com/watch?v=U0k15TMhW9w


	sf::Text GameOverText(font); //set text
	GameOverText.setString("Game Over");
	GameOverText.setCharacterSize(60);
	GameOverText.setPosition({ 250.f, 250.f });

	sf::Text scoreText(font); //set score
	scoreText.setCharacterSize(24);
	std::ostringstream output; //display the score as a string. https://stackoverflow.com/questions/12233710/how-do-i-use-the-ostringstream-properly-in-c
	output << "Score: " << score; 
	scoreText.setString(output.str());

	sf::Text RestartText(font);
	RestartText.setCharacterSize(24);
	RestartText.setPosition({ 280.f, 420.f });
	RestartText.setString("Press space to try again");

	if (GameOver)
	{
		window.draw(gameoverbg); //set background to transparent
		window.draw(GameOverText); //draw "game over"
		scoreText.setPosition({ 350.f, 350.f }); //reset the score under the game over text
		window.draw(scoreText); //draw the score
		window.draw(RestartText);
		
	}
	
	window.draw(scoreText); //draw the score in the corner
}

void Game::TestCollision()
{	
	for (int i = 1; i < snake.maxCurrentSize; i++) //if the snake hits any of its own bodyparts, game over
	{
		if (snake.size[0].loc.x == snake.size[i].loc.x &&
			snake.size[0].loc.y == snake.size[i].loc.y)
		{
			GameOver = true;
		}
	}

	
	if ((snake.size[0].loc.x == food.loc.x) && (snake.size[0].loc.y == food.loc.y))
		//I had trouble finding a good way to get a collision system going, but ended up stumbling across another persons code, who did not have the same question, but in their code I found their collision system to be-
		//-exactly what I needed.
		//https://stackoverflow.com/questions/60099274/how-can-i-define-a-game-over-in-snake-game-using-sfml
		//where if the snake's head collides with the x and the y of the food, you set a new position. Instead I set food.iseaten to true and set the position with <random>.
		
	{
		food.isEaten = true;
		Sound();
		
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
		moveDelay = sf::seconds(0.16f);
	}
	if (score >= 15)
	{
		moveDelay = sf::seconds(0.14f);
	}
	if (score >= 20)
	{
		moveDelay = sf::seconds(0.12f);
	}
	if (score >= 30)
	{
		moveDelay = sf::seconds(0.10f);
	}
	if (score >= 40)
	{
		moveDelay = sf::seconds(0.09f);
	}
	if (score >= 50)
	{
		moveDelay = sf::seconds(0.08f);
	}
	if (score >= 60)
	{
		moveDelay = sf::seconds(0.07f);
	}


}


void Game::Restart()
{
	//basically reset everything to how it was at the start
	GameOver = false;
	snake = Snake({ 10, 10 });
	score = 0;
	moveDelay = sf::seconds(0.2f);

	std::uniform_int_distribution<int> xDist(0, board.width - 1);
	std::uniform_int_distribution<int> yDist(0, board.height - 1);

	food.loc.x = xDist(rng); //set location
	food.loc.y = yDist(rng);
	food.isEaten = false;

	moveClock.restart();
}