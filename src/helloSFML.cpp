#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "PlayerFuncts.hpp"
#include "ScoreFuncts.hpp"
#include "WorldFuncts.hpp"


int main()
{
    Score playerScore;
    World world;
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dinoskater!");
    world.initialize();
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        world.update();
        // clear the window with black color
        window.clear(sf::Color::White);
        
        world.draw(window);
        
        window.display();
    }

    return 0;
}
