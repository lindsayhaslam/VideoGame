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
    
    void initialize();
    void update();
    
    //Reference to the window in main
    void draw(sf::RenderWindow& window);
    
    bool doesCollide(sf::FloatRect otherRect);
    
};

#endif /* PlayerFuncts_hpp */
