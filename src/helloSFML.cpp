#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "PlayerFuncts.hpp"
#include "ScoreFuncts.hpp"
#include "WorldFuncts.hpp"
#include "TestFuncts.hpp"


int main()
{
    Score score;
    World world;
    Player player;
    
    gameTests();
    
        
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dinoskater!");
    
    bool isGameOver = false;
    
    //Gradient Background
    sf::VertexArray gradient(sf::Quads, 4);

        // Define the colors for the gradient
        gradient[0].position = sf::Vector2f(0, 0);
        gradient[1].position = sf::Vector2f(800, 0);
        gradient[2].position = sf::Vector2f(800, 600);
        gradient[3].position = sf::Vector2f(0, 600);
    
        //Determine colors of the gradient
        gradient[0].color = sf::Color(135, 206, 250); // Sky Blue
        gradient[1].color = sf::Color(135, 206, 250); // Sky Blue
        gradient[2].color = sf::Color::White; // Light Sky Blue
        gradient[3].color = sf::Color::White; // Light Sky Blue

        //Call initialize methods for all parts of the game
        world.initialize();
        world.initializeCandy();
        score.initialize();
        score.initializeGameOverFont();
        auto lastUpdateTick = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());

    
    
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
        
        // Get the current absolute time in millesonds
        auto nowMS =std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());

        // get the delta time from the last update
        int deltaTimeMS = (nowMS - lastUpdateTick).count();
        lastUpdateTick = nowMS;

        //Used for buildings, candy, score
        world.update(deltaTimeMS);
        if (world.updateCandy(deltaTimeMS)){
            world.initializeCandy();
            score.updatePoints();
        }
        
        score.update(deltaTimeMS);
        
        //If player dies logic
         if (world.isPlayerDead())
        {
            score.drawGameOverText(window);
            window.display();

            isGameOver = true;
            // Additional game over logic (e.g., displaying a message)

            // Game over loop
                sf::Event event;
                while (isGameOver)
                {
                    //Pauses the game
                    if(window.pollEvent(event))
                    {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        return 0;
                    }
                    //Detects for and allows shift button to restart game
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::RShift || event.key.code ==sf::Keyboard::LShift)
                        {
                            // Resume the game
                            isGameOver = false;
                            
                        }
                    }
                }
            }
            //Reinitialize after the game over
            world.initialize();
            world.initializeCandy();
            score.initialize();
            score.initializeGameOverFont();
        }
        
        // Clear window
        window.clear();
        //Call draw for gradient
        window.draw(gradient);
        //Draw eindow
        world.draw(window);
        //Call drawCandy
        world.drawCandy(window);
        //Draw score
        score.draw(window);
        
        window.display();
    }

    return 0;
}
