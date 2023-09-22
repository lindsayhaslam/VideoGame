//
//  WorldFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#include "WorldFuncts.hpp"

void World::initialize(){
    std::srand(std::time(nullptr));
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
    
    //YUM!
        if (!candyCollectTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Yum.png"))
        {
            exit(0);
        }
        else
        {
            candyCollectedSprite.setTexture(candyCollectTexture);
        }
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
        candyPos=randCandyPos();
        candySprite.setScale(.2f, .2f); // Set width and height
        candySprite.setPosition(800.0f, candyPos); // Set position
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
            moveSpeed=randCandySpeed();
            //If so, move it back to edge 800.
            buildingSprite.setPosition(800.f, 437.f);
        }

    }
    player.update();
    
    if (player.doesCollide(buildingSprite.getGlobalBounds())) {
        playerDead=true;
    }
     
}

bool World::updateCandy (int deltatime)
{
//random number generator between two positions, then inser into the y
    for (int i=0; i <numCandies; ++i)
    {
        candySprite.move(-candyMoveSpeed, 0);
        //Check to see if rectangle has moved off screen
        if (candySprite.getPosition().x + candySprite.getScale().x < 0)
        {
            candyMoveSpeed=randCandySpeed();
            //If so, move it back to edge 800.
            candySprite.setPosition(800.0f, randCandyPos());
            
        }

    }
    
    if (player.doesCollide(candySprite.getGlobalBounds())) {
        
        player.currentTextureIndex = (player.currentTextureIndex + 1) % player.playerTextures.size();
        player.playerSprite.setTexture(player.playerTextures[player.currentTextureIndex]);
        
        
        //YUM!
        candyCollectedSprite.setTexture(candyCollectTexture);
        candyCollectedSprite.setPosition(player.playerSprite.getPosition());
        displayCandyCollected = true;
        candyCollectedTimer.restart();
        
        // YUM! Check if it's time to hide the candy collected sprite
        if (displayCandyCollected && candyCollectedTimer.getElapsedTime() >= displayDuration)
        {
                displayCandyCollected = false;
        }
        return true;
    }
    return false;
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
        for (int i=0; i<numCandies; ++i)
        {
            //draw rectangle along the way
            window.draw(candySprite);
        }
    //Draw YUM!
        if (displayCandyCollected)
        {
            window.draw(candyCollectedSprite);// Draw the candy collected sprite
            candyCollectedSprite.move(0.05f, -player.gravity);
        }

    }
    
    bool World::isPlayerDead()
    {
        return playerDead;
    }
    
