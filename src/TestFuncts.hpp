//
//  TestFuncts.hpp
//  testSFML
//
//  Created by Corinne Jones on 9/21/23.
//

#ifndef TestFuncts_hpp
#define TestFuncts_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "PlayerFuncts.hpp"
#include "ScoreFuncts.hpp"
#include "WorldFuncts.hpp"
#include <random>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <assert.h>

void gameTests();

void  testScoreInitialize();

void testInitializeGameOverFont();

void testScoreUpdate();

void testPlayerInitialize();

void testCollision();

void testRandomizeSpeed();

#endif /* TestFuncts_hpp */
