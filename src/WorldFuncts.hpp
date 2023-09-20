//
//  WorldFuncts.hpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#ifndef WorldFuncts_hpp
#define WorldFuncts_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "PlayerFuncts.hpp"
#include "ScoreFuncts.hpp"

class World
{
public:
    //RECTANGLE VARIABLES
    float moveSpeed = 0.04f;
    #define numRectangles 2
    sf::RectangleShape rectangles[numRectangles];
    Player dino;
    Score score;
    
    //Initialize rectangles with different initial positions
    void initialize(){
        for (int i=0; i < numRectangles; ++i)
        {
            rectangles[i].setSize(sf::Vector2f(50.0f, 100.0f)); // Set width and height
            rectangles[i].setPosition(800.0f + i * 400.0f, 437.0f); // Set position (x, y)
            rectangles[i].setFillColor(sf::Color::Black); // Set fill color
        }
        dino.initialize();
        score.initialize();
    }
    //RECTANGLES
          //Move and draw the rectangles
    void update ()
    {
        for (int i=0; i <numRectangles; ++i)
        {
            rectangles[i].move(-moveSpeed, 0);
            //Check to see if rectangle has moved off screen
            if (rectangles[i].getPosition().x + rectangles[i].getSize().x < 0)
            {
                //If so, move it back to edge 800.
                rectangles[i].setPosition(800.f, 437.f);
            }

        }
        dino.update();
        score.update();
    }
    
    void draw(sf::RenderWindow& window)
    {
        for (int i=0; i<numRectangles; ++i) {
            //draw rectangle along the way
            window.draw(rectangles[i]);
        }
        dino.draw(window);
        score.draw(window);
    }
};


#endif /* WorldFuncts_hpp */
