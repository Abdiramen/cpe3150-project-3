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
//char** drawGame(const Game *game) {
//    char** aliensAndShields = NULL;
//    const unsigned char numberOfAliens = game -> level;
//    const unsigned char shelterHeight = strlen(*shelter);
//    
//    const unsigned char numberOfShelters = game -> width / (strlen(shelter[0]) + 2.0); // the extra is for space to the left and right
//    const unsigned char spaceLeftOverFromShelter = game -> width % (strlen(shelter[0]) + 2);
//    
//    unsigned char i, j;
//    
//    
//    aliensAndShields = malloc(game -> width * sizeof(char));
//    for (int i = 0; i < game -> height - 1 - strlen(*gunner) ; i++) {
//        // we have to consider the height of the header (-1) and the height of the gunner
//        aliensAndShields[i] = malloc(game -> height - 1 - strlen(*gunner) * sizeof(char));
//    }
//    
//    // Draw Sheilds First
//    // i = height, j = width
//    //
//    // We add the space left over from the shelter because 
//    for (i = strlen(*aliensAndShields) + spaceLeftOverFromShelter / 2.0; i < shelterHeight - spaceLeftOverFromShelter / 2.0; i++) {
//        for (j = 0; j < game -> width; j++) {
//            
//        }
//    }
//    
//    
//    
//    return aliensAndShields;
//}

// MAINTENANCE FUNCTIONS
int power(int base, int exponent);
void numberToCharacter(const unsigned char number, char* string);
char* numberToString(int number, char *string);
unsigned char stringHeight(char** string);

#endif /* functions_h */
