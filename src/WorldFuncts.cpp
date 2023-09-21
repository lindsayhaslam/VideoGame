//
//  WorldFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#include "WorldFuncts.hpp"

void World::initialize(){

    if (!buildingTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Building.png"))
    {
    exit(0);
    }
    else
    {
        buildingSprite.setTexture(buildingTexture);
    }

        
    for (int i=0; i < numRectangles; ++i)
    {
        buildingSprite.setScale(.5f, .5f); // Set width and height
        buildingSprite.setPosition(800.0f + i * 400.0f, 437.0f); // Set position (x, y)
    }
    player.initialize();
    playerDead=false;
}

void World::initializeCandy(){

    if (!candyTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Candy.png"))
    {
    exit(0);
    }
    else
    {
        candySprite.setTexture(candyTexture);
    }

        
    for (int i=0; i < numCandies; ++i)
    {
        candySprite.setScale(.2f, .2f); // Set width and height
        candySprite.setPosition(800.0f + i * 400.0f, 100.0f); // Set position (x, y)
    }
}

void World::update (int deltatime)
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
        playerDead=true;
    }
     
}

void World::updateCandy (int deltatime)
{
//random number generator between two positions, then inser into the y
    for (int i=0; i <numCandies; ++i)
    {   std::srand(time(0));
        std::random_device rd;
        std::mt19937 gen(rd());
        
        double lowerBound = 400.0;
        double upperBound = 100.0;
        std::uniform_real_distribution<int> distribution(lowerBound, upperBound);
        int randomValue = distribution(gen);
        candySprite.move(-candyMoveSpeed, 0);
        //Check to see if rectangle has moved off screen
        if (candySprite.getPosition().x + candySprite.getScale().x < 0)
        {
            //If so, move it back to edge 800.
            candySprite.setPosition(800.0f, randomValue);
        }

    }
    
    if (player.doesCollide(candySprite.getGlobalBounds())) {
    
        player.currentTextureIndex = (player.currentTextureIndex + 1) % player.playerTextures.size();
            player.playerSprite.setTexture(player.playerTextures[player.currentTextureIndex]);
    }
     
}

void World::draw(sf::RenderWindow& window)
    {
        for (int i=0; i<numRectangles; ++i) {
            //draw rectangle along the way
            window.draw(buildingSprite);
        }
        player.draw(window);
    }

void World::drawCandy(sf::RenderWindow& window)
    {
        for (int i=0; i<numCandies; ++i) {
            //draw rectangle along the way
            window.draw(candySprite);
        }

    }
    
    bool World::isPlayerDead()
    {
        return playerDead;
    }
    
