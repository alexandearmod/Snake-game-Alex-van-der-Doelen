#include <SFML/Graphics.hpp>

int main() 
{
    sf::Font font;
    if (font.openFromFile("Midnight angel.ttf"));
    
    sf::Text text(font);
    text.setString("Hello world");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    //pre-made window function made by sfml. https://www.sfml-dev.org/tutorials/2.5/graphics-draw.php
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


        window.draw(text);

        /* --------------------------------------------------*/
        window.display();
    }

    return 0;
}