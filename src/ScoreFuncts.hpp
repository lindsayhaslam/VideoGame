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
    sf::Font scoreFont;
    int points=0;
    int numTicksSinceLastPoint = 0;
    const int numTicksPerPoint = 1000;
    
    Score()
    {
    }
    
    void initialize()
    {
        if (!scoreFont.loadFromFile("/Users/corinnejones/VideoGame/build/ARIAL.TTF"))
        {
            exit(0);
        }
        if (scoreFont.loadFromFile ("/Users/corinnejones/VideoGame/build/ARIAL.TTF"))
        {
            scoreText.setCharacterSize(30);
            scoreText.setPosition(300.f, 500.f);
            scoreText.setFillColor(sf::Color::Black);
            scoreText.setString("Score: ");
            numTicksSinceLastPoint = 0;
        }
    }
    
    void update(int delta)
        {
            numTicksSinceLastPoint += delta;
            if (numTicksSinceLastPoint >= numTicksPerPoint) {
                points++;
                scoreText.setString(std::to_string(points));
                numTicksSinceLastPoint = 0;
            }
        }
    
    void draw(sf::RenderWindow& window)
    {
        window.draw(scoreText);
    }
    
};

#endif /* ScoreFuncts_hpp */
