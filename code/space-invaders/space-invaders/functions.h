//
//  functions.h
//  space-invaders
//
//  Created by Illya Starikov on 11/10/16.
//  Copyright © 2016 Illya Starikov. All rights reserved.
//

#ifndef functions_h
#define functions_h

#include "game.h"
#include "point.h"
#include "constants.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// INITS / DEINITS
void initGame(Game* game);

// DRAWING LOGIC
char* createHeader(const Game *game);
char** drawShooter(const CartesianPoint center, const Game *game);
char** drawGame(Game *game);

// MAINTENANCE FUNCTIONS
int power(int base, int exponent);
void numberToCharacter(const unsigned char number, char* string);
char* numberToString(int number, char *string);
unsigned char stringHeight(char** string);

#endif /* functions_h */
