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

class Score
{
public:
    sf::Text scoreText;
    sf::Font scoreFont;
    int score=0;
    
    
    Score()
    {
    }
    
    void initialize()
        {
            scoreText.setFont(scoreFont);
            scoreText.setCharacterSize(30);
            scoreText.setPosition(300.f, 500.f);
            scoreText.setFillColor(sf::Color::Black);
            scoreText.setString("Score: ");
        }

    void update()
    {
        
        score++;
//        std::this_thread::sleep_for(std::chrono::seconds(1));
        scoreText.setString(std::to_string(score));
    }
    
    void draw(sf::RenderWindow& window)
    {
        window.draw(scoreText);
    }
    
};

#endif /* ScoreFuncts_hpp */
