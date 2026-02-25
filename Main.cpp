#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Location.h"
#include "Main.h"
    sf::Font font;
    sf::Text text1(font);

   
 
    int main()
    {
        if (!font.openFromFile("Midnight angel.ttf")) {
            return -1;
        }
        

        Board board;
        Location loc;
        loc.x = 100;
        loc.y = 100;

        sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Snake Game");

        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            window.clear(sf::Color::Black);
            /* Draw stuff between window.clear and window.display */
            
            
            
            board.DrawCell(window, loc, sf::Color::Blue);
           
            /* --------------------------------------------------*/
            window.display();
        }

        return 0;
    }

