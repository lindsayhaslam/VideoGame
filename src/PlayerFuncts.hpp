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
    bool isJumping = false;
    float jumpHeight = 450.0f;
    float gravity = .4f;
    
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
        //playerSprite.setFillColor(sf::Color(243, 100, 162));
        playerSprite.setPosition(250.f, 480.f);
        playerSprite.setScale(0.4f, 0.4f);
        }
            
    }

    void update()
    {
        //JUMP
        //Check if space key is pressed
               if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping)
               {
                   //Set isJumping to true;
                   isJumping = true;
               }
               
               if (isJumping)
               {
                   //Moves player upwards
                   playerSprite.move(0.f, -gravity);
                   jumpHeight -= gravity;
                   
                   if (jumpHeight <= 0)
                   {
                       isJumping = false;
                       jumpHeight = 200.0f;
                       gravity = 0.06f;
                   }
               }
               else if (playerSprite.getPosition().y < 480.f)
               {
                   playerSprite.move(0.f, gravity);
               }
        
    }
    
    //Reference to the window in main
    void draw(sf::RenderWindow& window)
    {
        window.draw(playerSprite);
    }
    
    bool doesCollide(sf::FloatRect otherRect){
        
        return playerSprite.getGlobalBounds().intersects(otherRect);
    }
    

    
};

#endif /* PlayerFuncts_hpp */
