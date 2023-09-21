//
//  PlayerFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#include "PlayerFuncts.hpp"


void Player::initialize(){
    if (!playerTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Dino.png"))
 {
    exit(0);
 }
    else
    {
    playerSprite.setTexture(playerTexture);
    isJumping = false;
    jumpHeight = 475.0f;
    gravity = .4f;
    playerSprite.setPosition(250.f, 480.f);
    playerSprite.setScale(0.4f, 0.4f);
    }
        
}

void Player::update()
    {
        // Check if the sprite is on the ground
        bool isOnGround = (playerSprite.getPosition().y >= 480.f);

        // JUMP
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

            if (jumpHeight <= 0)
            {
                isJumping = false;
                jumpHeight = 475.0f;
                gravity = 0.08f;
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

bool Player::doesCollide(sf::FloatRect otherRect)
{
    
    return playerSprite.getGlobalBounds().intersects(otherRect);
}
