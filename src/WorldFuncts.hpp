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
#include <stdlib.h>

class World
{
public:
    //RECTANGLE VARIABLES
    float moveSpeed = 0.04f;
    #define numRectangles 2
    sf::Texture buildingTexture;
    sf::Sprite buildingSprite[numRectangles];
    //sf::RectangleShape rectangles[numRectangles];
    Player dino;
    Score score;
    
    //Initialize rectangles with different initial positions
    void initialize(){
        for (int i=0; i < numRectangles; ++i)
        {
            buildingSprite[i].setScale(.5f, .5f); // Set width and height
            buildingSprite[i].setPosition(800.0f + i * 400.0f, 437.0f); // Set position (x, y)
            //buildingSprite[i].setFillColor(sf::Color::Black); // Set fill color
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
            buildingSprite[i].move(-moveSpeed, 0);
            //Check to see if rectangle has moved off screen
            if (buildingSprite[i].getPosition().x + buildingSprite[i].getScale().x < 0)
            {
                //If so, move it back to edge 800.
                buildingSprite[i].setPosition(800.f, 437.f);
            }

        }
        dino.update();
        score.update();
    }
    
    void draw(sf::RenderWindow& window)
    {
        for (int i=0; i<numRectangles; ++i) {
            //draw rectangle along the way
            window.draw(buildingSprite[i]);
        }
        dino.draw(window);
        score.draw(window);
    }
};


#endif /* WorldFuncts_hpp */
