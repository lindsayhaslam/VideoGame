//
//  PlayerFuncts.hpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#ifndef PlayerFuncts_hpp
#define PlayerFuncts_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Player
{
public:
    //PLAYER
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    //Jump variables
    bool isJumping;
    float jumpHeight;
    float gravity;
    
    
    Player()
    {
//build our constructor?
    }
    
    void initialize()
    {
        if (!playerTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Dino.png"))
     {
        exit(0);
     }
        else if(playerTexture.loadFromFile("/Users/corinnejones/VideoGame/build/Dino.png"))
        {
        playerSprite.setTexture(playerTexture);
        isJumping = false;
        jumpHeight = 450.0f;
        gravity = .4f;
        playerSprite.setPosition(250.f, 480.f);
        playerSprite.setScale(0.4f, 0.4f);
        }
            
    }

    void update()
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
                    jumpHeight = 425.0f;
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
    void draw(sf::RenderWindow& window)
    {
        window.draw(playerSprite);
    }
    
    bool doesCollide(sf::FloatRect otherRect)
    {
        
        return playerSprite.getGlobalBounds().intersects(otherRect);
    }

    
    

    
};

#endif /* PlayerFuncts_hpp */
