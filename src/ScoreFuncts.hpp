//
//  ScoreFuncts.hpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#ifndef ScoreFuncts_hpp
#define ScoreFuncts_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>

class Score
{
public:
    sf::Text scoreText;
    sf::Text gameOverText;
    sf::Font font;
    int points=0;
    int numTicksSinceLastPoint = 0;
    const int numTicksPerPoint = 1000;
    
    void initialize();
    
    void initializeGameOverFont(); 
    
    void update(int delta);
    
    void draw(sf::RenderWindow& window);
    
    void drawGameOverText(sf::RenderWindow& window);
    
    void updatePoints();

    
};

#endif /* ScoreFuncts_hpp */
