#include "Game.h"
#include <random>
Game::Game(sf::RenderWindow& window)
	:
	window(window), //store a reference to window
	rng(std::random_device{}()) //initializer random generator
{


}

void Game::Go()
{
}
std::uniform_int_distribution<int> ColorDist(0, 255);
std::mt19937 rng;

sf::Color Game::RandomColor()
{
    return sf::Color(
        ColorDist(rng),
        ColorDist(rng),
        ColorDist(rng)
    );
}