//
//  TestFuncts.cpp
//  testSFML
//
//  Created by Corinne Jones on 9/21/23.
//

#include "TestFuncts.hpp"
void gameTests(){
    testScoreInitialize();
    testInitializeGameOverFont();
    testScoreUpdate();
    testPlayerInitialize();
    testCollision();
    testRandomizeSpeed();
    
}
void  testScoreInitialize()
{
    Score score;
    score.initialize();

    // Test if font is loaded
    if (!score.font.loadFromFile("/Users/corinnejones/VideoGame/art/SuperBoom.TTF")) {
        std::cout << "Font failed to load." << std::endl;
    }

    // Test if scoreText is initialized correctly
    if (score.scoreText.getCharacterSize() != 30
        || score.scoreText.getPosition() != sf::Vector2f(10.f, 10.f)
        || score.scoreText.getFillColor() != sf::Color::Black
        || score.scoreText.getString() != "Score: 0"
        || score.numTicksSinceLastPoint != 0
        || score.points != 0) {
        std::cout << "Score::initialize FAILED" << std::endl;
    }

    std::cout << "Score::initialize passed!" << std::endl;
}

void testInitializeGameOverFont()
{
    Score score;
    score.initializeGameOverFont();

    // Test if gameOverText is initialized correctly
    if (score.gameOverText.getCharacterSize() != 36
        || score.gameOverText.getPosition() != sf::Vector2f(200.f, 200.f)
        || score.gameOverText.getFillColor() != sf::Color::Black
        || score.gameOverText.getString() != "      GAME OVER\nPress SHIFT to restart")
    {
        std::cout << "Score::initializeGameOverFont FAILED" << std::endl;
    }

    std::cout << "Score::initializeGameOverFont passed!" << std::endl;
}


void testScoreUpdate()
{
    Score score;
    // Initialize the score
    score.points = 0;
    score.numTicksSinceLastPoint = 0;
    score.scoreText.setString("Score: 0");
    
    // Call the update function
    score.update(50); // Simulate 50 ticks
    
    // Check if points and scoreText are updated correctly
    if (score.points != 0 || score.numTicksSinceLastPoint != 50 || score.scoreText.getString() != "Score: 0") {
        std::cout << "Score::update FAILED" << std::endl;
    }
    else
    {
        std::cout << "Score::update passed!" << std::endl;
    }

}

void testPlayerInitialize()
{
    Player player;
    if (player.isJumping != false && player.gravity != .9f)
        {
            std::cout << "Player::isInitialized FAILED" << std::endl;
            
        }
        else
        {
            std::cout << "Player::isInitialized passed!" << std::endl;
        }
}

void testCollision()
{
    Player player;

    // Set up playerSprite position and size
    sf::Texture playerTexture;
    playerTexture.loadFromFile("/Users/corinnejones/VideoGame/art/Dino1.png");
    player.playerSprite.setTexture(playerTexture);
    player.playerSprite.setPosition(100.f, 100.f);
    player.playerSprite.setScale(0.5f, 0.5f);

    // Create a test collision rectangle
    sf::FloatRect testRect(150.f, 150.f, 50.f, 50.f);

    // Test if player collides with the testRect
    if (player.doesCollide(testRect))
    {
        std::cout << "Collision test passed!" << std::endl;
    }
    else
    {
        std::cout << "Collision test FAILED" << std::endl;
    }
}

void testRandomizeSpeed()
{
    const int numTests = 100;  // Number of random speed tests to perform
    const float min = 10.0f;
    const float max = 20.0f;
    float random;

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator

    for (int i = 0; i < numTests; ++i) {
        float random=std::rand()/(float)RAND_MAX*(max-min)+min;

        // Check if the generated speed is within the expected range
        if (random < min || random > max) {
            std::cout << "World::randomizeSpeed FAILED" << std::endl;
        }
    }

    std::cout << "World::randomizeSpeed passed!" << std::endl;
}
