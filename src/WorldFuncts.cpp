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

void World::draw(sf::RenderWindow& window)
    {
        for (int i=0; i<numRectangles; ++i) {
            //draw rectangle along the way
            window.draw(buildingSprite);
        }
        player.draw(window);

    }
    
    bool World::isPlayerDead()
    {
        return playerDead;
    }
    
