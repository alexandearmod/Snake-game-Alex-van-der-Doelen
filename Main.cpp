#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Location.h"
#include "Main.h"
#include "Game.h"
#include "Snake.h"
    
    
  
 
    int main()
    {
       
        sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Snake Game");
        Board board;
        Game game(window);
       



        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
           


            window.clear(sf::Color::Black);
            /* Draw stuff between window.clear and window.display */
            game.Go();
           
            
            /* --------------------------------------------------*/
            window.display();
        }

        return 0;
    }

