//
//  PlayerFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//
#include "PlayerFuncts.hpp"

void Player::initialize()
{
    //Load files into their respectuive textures
    //Purple dino
    if (!purpleTexture.loadFromFile("../art/Dino.png")) {
        std::cerr << "Failed to load playerTexture" << std::endl;
        exit(1);
    }
    
    //Orange dino
    if (!orangeTexture.loadFromFile("../art/Dino1.png")) {
        std::cerr << "Failed to load orangeTexture" << std::endl;
        exit(1);
    }
    
    //Green dino
    if (!greenTexture.loadFromFile("../art/Dino2.png")) {
        std::cerr << "Failed to load greenTexture" << std::endl;
        exit(1);
    }
    else {
    //Push back different textures into playerTextures vector
    playerTextures.push_back(purpleTexture);
    playerTextures.push_back(orangeTexture);
    playerTextures.push_back(greenTexture);
    
    //Set playerSprite texture to [[0]
    playerSprite.setTexture(playerTextures[0]);
        
    //Default settings
    isJumping = false;
    jumpHeight = 475.0f;
    gravity = .9f;
    playerSprite.setPosition(200.f, 480.f);
    playerSprite.setScale(0.4f, 0.4f);
 
        
    }
        
}


void Player::update()
    {
        // Check if the sprite is on the ground by its "y" position
    bool isOnGround = (playerSprite.getPosition().y >= 480.f);

        // Jump when spacebar is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping && isOnGround)
        {
            // Set isJumping to true
            isJumping = true;
            isOnGround = false; // Mark that the sprite is no longer on the ground
        }

        if (isJumping)
        {
            // Moves player upwards
            playerSprite.move(0.f, -gravity);
            jumpHeight -= gravity;

            //When jumpHeight is less than or equal to zero, player is not jumping
            if (jumpHeight <= 0)
            {
                isJumping = false;
                jumpHeight = 480.0f;
                gravity = 0.075f;
            }
        }
        else if (!isOnGround)
        {
            // If not jumping and not on the ground, apply gravity
            playerSprite.move(0.f, gravity);
        }
        else
        {
            // If on the ground, reset jumpHeight and gravity
            jumpHeight = 425.0f;
            gravity = 0.08f;
        }
        
    }

//Reference to the window in main
void Player::draw(sf::RenderWindow& window)
{
    window.draw(playerSprite);
}

//Collision deteection
bool Player::doesCollide(sf::FloatRect otherRect)
{
    
    return playerSprite.getGlobalBounds().intersects(otherRect);
}


