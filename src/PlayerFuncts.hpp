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

class Player
{
public:
    //PLAYER
    sf::CircleShape playerShape{30.f};
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
        
        isJumping = false;
        jumpHeight = 450.0f;
        gravity = .4f;
        playerShape.setFillColor(sf::Color(243, 100, 162));
        playerShape.setPosition(250.f, 480.f);
        playerShape.setRadius(30.f);
            
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
                   playerShape.move(0.f, -gravity);
                   jumpHeight -= gravity;
                   
                   if (jumpHeight <= 0)
                   {
                       isJumping = false;
                       jumpHeight = 200.0f;
                       gravity = 0.06f;
                   }
               }
               else if (playerShape.getPosition().y < 480.f)
               {
                   playerShape.move(0.f, gravity);
               }
        
    }
    
    void draw(sf::RenderWindow& window)
    {
        window.draw(playerShape);
    }
    

    
};

#endif /* PlayerFuncts_hpp */
