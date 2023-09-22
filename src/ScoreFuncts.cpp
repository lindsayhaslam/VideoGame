//
//  ScoreFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/19/23.
//

#include "ScoreFuncts.hpp"


void Score::initialize()
{
    //Load font
    if (!font.loadFromFile("/Users/lindsayhaslam/LindsayCorinneFinalProject/VideoGame/build/SuperBoom.TTF"))
    {
        exit(0);
    }
    //Default settings for scoreText
    else
    {   scoreText.setFont(font);
        scoreText.setCharacterSize(50);
        scoreText.setPosition(10.f, 10.f);
        scoreText.setFillColor(sf::Color::Black);
        scoreText.setString("Score: 0");
        numTicksSinceLastPoint = 0;
    }
    points = 0;
}

//Creating the "Game Over" text
void Score::initializeGameOverFont()
{
    gameOverText.setFont(font);
    gameOverText.setString("         GAME OVER\nPress SHIFT to restart");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(sf::Color::Black);
    gameOverText.setPosition(130, 200);
}

//This function updates the score each second. We start by passing in the time.
void Score::update(int delta)
    {
    //This keeps track of the time that has passed and adds a tick each second
        numTicksSinceLastPoint += delta;
    //If this condition is true, then increment the points by one.
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
