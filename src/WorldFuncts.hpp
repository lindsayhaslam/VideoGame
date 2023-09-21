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
//everywhere it has the numRectangles it is iterating twice and doing two times the number of things to buildingSprite.

class World
{
public:
    //RECTANGLE VARIABLES
    float moveSpeed = 0.04f;
    #define numRectangles 1
    sf::Texture buildingTexture;
    sf::Sprite buildingSprite;
    //sf::RectangleShape rectangles[numRectangles];
    Player player;
    Score score;
    
    //Initialize rectangles with different initial positions
    void initialize(){
        
        if (!buildingTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Building.png"))
     {
        exit(0);
     }
        else if(buildingTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Building.png"))
        {
            buildingSprite.setTexture(buildingTexture);
        }
            
        for (int i=0; i < numRectangles; ++i)
        {
            buildingSprite.setScale(.5f, .5f); // Set width and height
            buildingSprite.setPosition(800.0f + i * 400.0f, 437.0f); // Set position (x, y)
        }
        player.initialize();
        score.initialize();
    }
    //RECTANGLES
          //Move and draw the rectangles
    void update ()
    {
        for (int i=0; i <numRectangles; ++i)
        {
            buildingSprite.move(-moveSpeed, 0);
            //Check to see if rectangle has moved off screen
            if (buildingSprite.getPosition().x + buildingSprite.getScale().x < 0)
            {
                //If so, move it back to edge 800.
                buildingSprite.setPosition(800.f, 437.f);
            }

        }
        player.update();
        
        if (player.doesCollide(buildingSprite.getGlobalBounds())) {
            buildingSprite.setPosition(0,0);
        }
        
        score.update(0);
    }
    
    void draw(sf::RenderWindow& window)
    {
        for (int i=0; i<numRectangles; ++i) {
            //draw rectangle along the way
            window.draw(buildingSprite);
        }
        player.draw(window);
        score.draw(window);
    }
};


#endif /* WorldFuncts_hpp */
