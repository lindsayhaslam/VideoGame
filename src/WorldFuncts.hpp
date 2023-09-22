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
private:
    //Yum! Sprites
    sf::Texture candyCollectTexture;
    sf::Sprite candyCollectedSprite; // New sprite for displaying collected candy
    bool displayCandyCollected = false; // Flag to control the display
    sf::Clock candyCollectedTimer; // Timer to track the display duration
    const sf::Time displayDuration = sf::seconds(4.0f); // Duration in seconds for displaying the candy
    
public:
    //RECTANGLE VARIABLES
    float moveSpeed= 0.04;
    float candyMoveSpeed=0.01;
    int candyPos;
    int numRectangles=1;
    int numCandies=1;
    sf::Texture buildingTexture;
    sf::Sprite buildingSprite;
    sf::Texture candyTexture;
    sf::Sprite candySprite;
    bool playerDead=false;
    Player player;

    
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
        return randomizeSpeed(.03, .11);
    }
    
    float randBuildingSpeed()
    {
        return randomizeSpeed(.058, .070);
        
    }
    
    float randomizeSpeed(float min, float max)
    {
        float randomSpeed=std::rand()/(float)RAND_MAX*(max-min)+min;
        return randomSpeed;
        
    }
    
    
    
};

#endif /* WorldFuncts_hpp */
