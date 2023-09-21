#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "PlayerFuncts.hpp"
#include "ScoreFuncts.hpp"
#include "WorldFuncts.hpp"

//class Game
//{
//    public:
//        void initialize()
//        {
//            
//        }
//        
//        void update(int n)
//        {
//            
//        }
//        
//        void draw()
//        {
//            
//        }
//};

// Initialze the absolute time in millesconds
//auto lastUpdateTick = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());

// normal game initialization
//        game.initialize();
//        while (running) {
//            // Get the current absolute time in millesonds
//            auto nowMS = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
//
//            // get the delta time from the last update
//            int deltaTimeMS = (nowMS - lastUpdateTick).count();
//            game.update(deltaTimeMS);
//            game.draw();
//            // Set the last update to now
//            lastUpdateTick = nowMS;
//        }



int main()
{
    Score playerScore;
    World world;
        
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dinoskater!");
    
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
        auto nowMS = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());

        // get the delta time from the last update
//        int deltaTimeMS = (nowMS - lastUpdateTick).count();
        
        world.update();
        
        //if world.isplayerdead do the end of game logic. 
        
        // clear the window with white color
        window.clear();
        
        window.draw(gradient);

        world.draw(window);
        
        window.display();
    }

    return 0;
}
