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
#include <vector>
#include <iostream>


class Player
{
public:
    //PLAYER
    sf::Texture purpleTexture;
    sf::Sprite playerSprite;
    //Jump variables
    bool isJumping;
    float jumpHeight;
    float gravity;
    
    std::vector<sf::Texture> playerTextures;
    int currentTextureIndex = 0;
    sf::Texture orangeTexture;
    sf::Texture greenTexture;
    
    void initialize();
    
    
    void update();
    void colorUpdate();
    
    //Reference to the window in main
    void draw(sf::RenderWindow& window);
    void colorDraw();
    
    
    
    bool doesCollide(sf::FloatRect otherRect);
    void doesCollideCandy(Player& player); 
    
};

#endif /* PlayerFuncts_hpp */
