#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "PlayerFuncts.hpp"
#include "ScoreFuncts.hpp"
#include "WorldFuncts.hpp"

void backgroundGradient()
{
    sf::VertexArray gradient(sf::Quads, 4);

        // Define the colors for the gradient
        gradient[0].position = sf::Vector2f(0, 0);
        gradient[1].position = sf::Vector2f(800, 0);
        gradient[2].position = sf::Vector2f(800, 600);
        gradient[3].position = sf::Vector2f(0, 600);


        gradient[0].color = sf::Color(173, 216, 230);
        gradient[1].color = sf::Color(173, 216, 230);
        gradient[2].color = sf::Color::White;
        gradient[3].color = sf::Color::White;
}

int main()
{
    Score score;
    World world;
    Player player;
    
        
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dinoskater!");
    
    bool isGameOver = false;
    
    sf::VertexArray gradient(sf::Quads, 4);

        // Define the colors for the gradient
        gradient[0].position = sf::Vector2f(0, 0);
        gradient[1].position = sf::Vector2f(800, 0);
        gradient[2].position = sf::Vector2f(800, 600);
        gradient[3].position = sf::Vector2f(0, 600);


        gradient[0].color = sf::Color(173, 216, 230);
        gradient[1].color = sf::Color(173, 216, 230);
        gradient[2].color = sf::Color::White;
        gradient[3].color = sf::Color::White;


    world.initialize();
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

        world.update(deltaTimeMS);
        score.update(deltaTimeMS);
        
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
                    if(window.pollEvent(event))
                    {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                        return 0;
                    }

                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::RShift || event.key.code ==sf::Keyboard::LShift)
                        {

                            isGameOver = false; // Resume the game
                            
                        }
                    }
                }
            }
            world.initialize();
            score.initialize();
            score.initializeGameOverFont();
        }
        
        // clear the window with white color
        window.clear();
        
        window.draw(gradient);

        world.draw(window);
        score.draw(window);
        
        window.display();
    }

    return 0;
}
