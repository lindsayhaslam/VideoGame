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
    float moveSpeed=0.06;
    int numRectangles=1;
    sf::Texture buildingTexture;
    sf::Sprite buildingSprite;
    bool playerDead=false;
    //sf::RectangleShape rectangles[numRectangles];
    Player player;
    //Score score;
    sf::RectangleShape road;
    
    //Initialize rectangles with different initial positions
    void initialize();

    //RECTANGLES
          //Move and draw the rectangles
    void update (int deltatime);
    
    void draw(sf::RenderWindow& window);
    
    bool isPlayerDead(); 
    
};

#endif /* WorldFuncts_hpp */
