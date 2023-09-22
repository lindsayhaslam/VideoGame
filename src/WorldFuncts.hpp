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
#include <random>
#include <ctime>
#include <vector>
#include <iostream>
#include <cstdlib>
//everywhere it has the numRectangles it is iterating twice and doing two times the number of things to buildingSprite.

class World
{
public:
    //RECTANGLE VARIABLES
    float moveSpeed;
    float candyMoveSpeed;
    int candyPos;
    int numRectangles=1;
    int numCandies=1;
    sf::Texture buildingTexture;
    sf::Sprite buildingSprite;
    sf::Texture candyTexture;
    sf::Sprite candySprite;
    bool playerDead=false;
    //sf::RectangleShape rectangles[numRectangles];
    Player player;
//    Score score;
//    sf::RectangleShape road;
    
    //Initialize rectangles with different initial positions
    void initialize();
    
    void initializeCandy(); 

    //RECTANGLES
          //Move and draw the rectangles
    void update (int deltatime);
    
    bool updateCandy (int deltatime); 
    
    void draw(sf::RenderWindow& window);
    
    void drawCandy (sf::RenderWindow& window);
    
    bool isPlayerDead();
    
    int randCandyPos()
    {
        int max=500;
        int min=25;
        int randomValue=std::rand()/(float)RAND_MAX*(max-min)+min;
        return randomValue; 
    }
    
    float randCandySpeed()
    {
        float max = 0.10;
        float min =0.001;
        float randomSpeed=std::rand()/(float)RAND_MAX*(max-min)+min;
        return randomSpeed;
    }
    
    float randBuildingSpeed()
    {   float max = 0.08;
        float min =0.03;
        float randomSpeed=std::rand()/(float)RAND_MAX*(max-min)+min;
        return randomSpeed;
        
    }
    
    
    
};

#endif /* WorldFuncts_hpp */
