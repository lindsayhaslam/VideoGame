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
    
    Score()
    {
    }
    
    void initialize()
    {
        if (!font.loadFromFile("/Users/corinnejones/VideoGame/build/ARIAL.TTF"))
        {
            exit(0);
        }
        else
        {   scoreText.setFont(font);
            scoreText.setCharacterSize(30);
            scoreText.setPosition(10.f, 10.f);
            scoreText.setFillColor(sf::Color::Black);
            scoreText.setString("Score: 0");
            numTicksSinceLastPoint = 0;
        }
        points = 0;
    }
    
    void initializeGameOverFont()
    {
        gameOverText.setFont(font);
        gameOverText.setString("        GAME OVER\nPress SHIFT to restart");
        gameOverText.setCharacterSize(36);
        gameOverText.setFillColor(sf::Color::Black);
        gameOverText.setPosition(200, 200);
    }
    
    void update(int delta)
        {
            numTicksSinceLastPoint += delta;
            if (numTicksSinceLastPoint >= numTicksPerPoint) {
                points++;
                scoreText.setString(std::string("Score: ") + std::to_string(points));
                numTicksSinceLastPoint = 0;
            }
        }
    
    void draw(sf::RenderWindow& window)
    {
        window.draw(scoreText);
    }
    
    void drawGameOverText(sf::RenderWindow& window)
    {
        window.draw(gameOverText);
    }
    
};

#endif /* ScoreFuncts_hpp */
