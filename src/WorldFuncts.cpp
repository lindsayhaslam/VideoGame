//
//  WorldFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#include "WorldFuncts.hpp"

void World::initialize(){
    
    //Create a rectangle shape for the ground
    groundRect.setSize(sf::Vector2(800.f, 17.f));
    groundRect.setFillColor(sf::Color(110, 105, 105));
    groundRect.setPosition(0.f, 583.f);
    
    //Seeding the random for World helper functions
    std::srand(std::time(nullptr));
    
    //Load in Building.png to a texture and then assign it to a sprite
    if (!buildingTexture.loadFromFile("/Users/lindsayhaslam/LindsayCorinneFinalProject/VideoGame/build/Building.png"))
    {
    exit(0);
    }
    else
    {
        buildingSprite.setTexture(buildingTexture);
    }

    //Set scale and position for buildingSprite
    for (int i=0; i < numRectangles; ++i)
    {
        buildingSprite.setScale(.5f, .5f); // Set width and height
        buildingSprite.setPosition(800.0f + i * 400.0f, 437.0f); // Set position (x, y)
    }
    player.initialize();
    playerDead=false;
    
    //Load in "Yum" for candyCollectTexture and then assign it to candyCollectedSprite sprite
    if (!candyCollectTexture.loadFromFile("/Users/lindsayhaslam/LindsayCorinneFinalProject/VideoGame/build/Yum.png"))
    {
        exit(0);
    }
    else
    {
        candyCollectedSprite.setTexture(candyCollectTexture);
    }
}

void World::initializeCandy(){
    //Load in Candy.png for candyTexture and then assign it to candySprite
    if (!candyTexture.loadFromFile("/Users/lindsayhaslam/LindsayCorinneFinalProject/VideoGame/build/Candy.png"))
    {
    exit(0);
    }
    else
    {
        candySprite.setTexture(candyTexture);
    }

    //Candy hits end of the screen, it generates a random set position
    for (int i=0; i < numCandies; ++i)
    {
        candyPos=randCandyPos();
        candySprite.setScale(.2f, .2f); // Set width and height
        candySprite.setPosition(800.0f, candyPos); // Set position
    }
}

void World::update (int deltatime)
{
    //Use a for-loop to get the building to move and to reset position
    for (int i=0; i <numRectangles; ++i)
    {
        
        buildingSprite.move(-moveSpeed, 0);
        //Check to see if rectangle has moved off screen
        if (buildingSprite.getPosition().x + buildingSprite.getScale().x < 0)
        {
            moveSpeed=randBuildingSpeed();
            //If so, move it back to edge 800.
            buildingSprite.setPosition(800.f, 437.f);
        }

    }
    player.update();
    
    //If player collides with building, player is dead
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
    //Color changing feature
    //When there is a collision, increase the currentTextureIndex reset the texture of the playerSprite
    if (player.doesCollide(candySprite.getGlobalBounds())) {
        player.currentTextureIndex = (player.currentTextureIndex + 1) % player.playerTextures.size();
        player.playerSprite.setTexture(player.playerTextures[player.currentTextureIndex]);
        
        
        //Set candy texture
        //Set the "yum" image at the position of the player's position
        //Set displayCandyCollected to true
        //Restart the candyCollectedTimer
        candyCollectedSprite.setTexture(candyCollectTexture);
        candyCollectedSprite.setPosition(player.playerSprite.getPosition());
        displayCandyCollected = true;
        candyCollectedTimer.restart();
        
        // Check if it's time to hide "Yum"
        if (displayCandyCollected && candyCollectedTimer.getElapsedTime() >= displayDuration)
        {
                displayCandyCollected = false;
        }
        return true;
    }
    return false;
}

//Draw buildings and the ground
void World::draw(sf::RenderWindow& window)
    {
        for (int i=0; i<numRectangles; ++i) {
            //draw rectangle along the way
            window.draw(buildingSprite);
        }
        window.draw(groundRect);
        player.draw(window);
    
    }
//Draw the candy along the screen
//Draw "Yum" when collision occurs
void World::drawCandy(sf::RenderWindow& window)
    {
        for (int i=0; i<numCandies; ++i)
        {
            //draw candySprite along the way
            window.draw(candySprite);
        }
    //Draw "Yum"
    //Have the "Yum" sprite float slightly to the right and to the top
        if (displayCandyCollected)
        {
            window.draw(candyCollectedSprite);
            candyCollectedSprite.move(0.05f, -player.gravity);
        }

    }

    
    bool World::isPlayerDead()
    {
        return playerDead;
    }
    
