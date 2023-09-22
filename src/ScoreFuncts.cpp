//
//  ScoreFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#include "ScoreFuncts.hpp"


void Score::initialize()
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

void Score::initializeGameOverFont()
{
    gameOverText.setFont(font);
    gameOverText.setString("      GAME OVER\nPress SHIFT to restart");
    gameOverText.setCharacterSize(36);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(200, 200);
}

void Score::update(int delta)
    {
        numTicksSinceLastPoint += delta;
        if (numTicksSinceLastPoint >= numTicksPerPoint) {
            points++;
            scoreText.setString(std::string("Score: ") + std::to_string(points));
            numTicksSinceLastPoint = 0;
        }
    }

void Score::draw(sf::RenderWindow& window)
{
    window.draw(scoreText);
}

void Score::drawGameOverText(sf::RenderWindow& window)
{
    window.draw(gameOverText);
}

void Score::updatePoints()
{
    points+=10;
}
