#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Location.h"
#include "Main.h"
#include "Game.h"
    sf::Font font;
    sf::Text text1(font);
    
  
 
    int main()
    {
        if (!font.openFromFile("Midnight angel.ttf")) {
            return -1;
        }
        
        
        Board board;
        Location loc;
        loc.x = 0;
        loc.y = 0;
        loc.x = loc.x * board.dimension;
        loc.y = loc.y * board.dimension;
       
        sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Snake Game");

        Game game(window);
        
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            game.Go();


            window.clear(sf::Color::Black);
            /* Draw stuff between window.clear and window.display */
            
            //board.DrawCell(window, loc, sf::Color::Blue);
            

            for (int y = 0; y < board.height; y++)
            {
                for (int x = 0; x < board.width; x++)
                {
                    Location loc{ x, y };
                    board.DrawCell(window, loc, game.RandomColor());
                };
                
            }
           
            /* --------------------------------------------------*/
            window.display();
        }

        return 0;
    }

