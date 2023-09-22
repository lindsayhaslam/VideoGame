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
    
    //YUM VARIABLES
    sf::Texture candyCollectTexture;
    // New sprite for displaying collected candy
    sf::Sprite candyCollectedSprite;
    // Flag to control the display
    bool displayCandyCollected = false;
    // Timer to track the display duration
    sf::Clock candyCollectedTimer;
    // Duration in seconds for displaying the candy
    const sf::Time displayDuration = sf::seconds(4.0f);
    
    //RECTANGLE VARIABLES
    float moveSpeed= 0.04;
    int numRectangles=1;
    sf::Texture buildingTexture;
    sf::Sprite buildingSprite;
    //For the ground
    sf::RectangleShape groundRect;
    
    //CANDY VARIABLES
    int candyPos;
    float candyMoveSpeed=0.01;
    int numCandies=1;
    sf::Texture candyTexture;
    sf::Sprite candySprite;
    
    //PLAYER
    bool playerDead=false;
    Player player;

    
    void initialize();
    
    void initializeCandy(); 

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
        return randomizeSpeed(.045, .075);
        
    }
    
    float randomizeSpeed(float min, float max)
    {
        float randomSpeed=std::rand()/(float)RAND_MAX*(max-min)+min;
        return randomSpeed;
        
    }
    
    
    
    
};

#endif /* WorldFuncts_hpp */
