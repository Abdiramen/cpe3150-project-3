//
//  functions.c
//  space-invaders
//
//  Created by Illya Starikov on 11/10/16.
//  Copyright © 2016 Illya Starikov. All rights reserved.
//

#include "functions.h"
#include "constants.h"
#include "game.h"
#include "point.h"

#include <stdlib.h>
#include <string.h>

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>



void initGame(Game* game) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    game -> height = w.ws_row;
    game -> width = w.ws_col;
    
    game -> level = 1;
    game -> lives = 3;
    game -> score = 0;
    
    game -> gameBoard = malloc(game -> width * sizeof(char*));
    for (int i = 0; i < game -> height; i++) {
        game -> gameBoard[i] = malloc(game -> height * sizeof(char));
    }
}

char* createHeader(const Game *game) {
    static char* headerLine = NULL;
    unsigned char workingSize = game -> width; // working size is to keep track how much room is left for the header line
    char tempString[2];
    
    headerLine = malloc(game -> width * sizeof(char));
    
    if (workingSize > strlen(NAME)) {
        strcat(headerLine, NAME);
        workingSize -= strlen(NAME);
    }
    
    
    if (workingSize > strlen(LIVES) + sizeof(tempString)) {
        strcat(headerLine, LIVES);
        strcat(headerLine, numberToString(game -> lives, tempString));
        workingSize -= strlen(NAME);
    }
    
    if (workingSize > strlen(SCORE) + sizeof(tempString)) {
        strcat(headerLine, SCORE);
        strcat(headerLine, numberToString(game -> score, tempString));
        workingSize -= strlen(NAME);
    }
    
    return headerLine;
}

// Note: the center actually ignores height. ¯\_(ツ)_/¯
char** drawShooter(const CartesianPoint center, const Game *game) {
    const unsigned char width = sizeof(*gunner);
    const unsigned char height = sizeof(gunner) / width; //works like stringHeight, but can't use it because incompatible pointers
    
    char** shooterAscii = NULL;
    unsigned char i, j, shooterCounter;

    shooterAscii = malloc(game -> width * sizeof(char*));
    for (int i = 0; i < height; i++) {
        shooterAscii[i] = malloc(height * sizeof(char));
    }
    
    for (j = 0; j < height; j++) {
        shooterCounter = 0;
        for (i = 0; i < game -> width; i++) {
            
            // the if determines if the shooter should be drawn, and it works like so:
            // if it's in the range of 1/2width on either side of the center, then it's a match
            // -1 because used sizeof for width calculation and that includes terminating character
            if (i + strlen(*gunner)/2.0 >= center.x && i - strlen(*gunner)/2.0 <= center.x ) {
                shooterAscii[j][i] = gunner[j][shooterCounter];
                shooterCounter++;
            } else {
                shooterAscii[j][i] = ' ';
            }
        }
        shooterAscii[j][i] = '\0';
        
        /* 
         Error Here
         
         Essentially, the first line gets modified, even though there is nothing above that should mutate it.
         Don't know why, don't know how.
         
         There are two lines below that print out the array, uncommenting the first one should show that the first line gets modified to.         
         */
//        printf("%s\n", shooterAscii[0]); // This prints out the 0th line everytime. However, it randomly changes.
//        printf("%s\n", shooterAscii[j]); // This prints out the line that is currently being written to
    
    }

   
    

    return shooterAscii;
}

char** drawGame(Game *game) {
    char** aliensAndShields = NULL;
    unsigned char numberOfAliens;
    const unsigned char shelterHeight = strlen(*shelter);
    
    const unsigned char numberOfShelters = game -> width / (strlen(shelter[0]) + 2.0); // the extra is for space to the left and right
    const unsigned char spaceLeftOverFromShelter = game -> width % (strlen(shelter[0]) + 2);
    const unsigned char height = game -> height - 1 + sizeof(gunner)/sizeof(*gunner); // read string height to figure out how this works
    // we subtract 1 for the header string and the gunner height becuase this is this the "working canvas"
    
    unsigned char i, j;
    
    if (game -> currentNumberOfAliens == 0) {
        game -> currentNumberOfAliens = game -> level;
        numberOfAliens = game -> level;
    } else {
        numberOfAliens = game -> currentNumberOfAliens;
    }
    
    // ERROR IS HERE
    aliensAndShields = malloc(game -> width * sizeof(char*));
    for (int i = 0; i < height; i++) {
        aliensAndShields[i] = malloc(height * sizeof(char));
    }
    
//    shooterAscii = malloc(game -> width * sizeof(char));
//    for (int i = 0; i < height; i++) {
//        shooterAscii[i] = malloc(height * sizeof(char));
//    }
    
    // Draw Sheilds First
    // i = row, j = column
    //
    // We add the space left over from the shelter because
//    for (i = strlen(*aliensAndShields) + spaceLeftOverFromShelter / 2.0; i < shelterHeight - spaceLeftOverFromShelter / 2.0; i++) {
//        for (j = 0; j < game -> width; j++) {
//            aliensAndShields[i][j] = shelter[i][j % strlen(*shelter)];
//        }
//    }
    
    return aliensAndShields;
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    
    return base * power(base, exponent - 1);
}

char* numberToString(int number, char *string) {
    if (string == NULL) {
        return NULL;
    }
    
    sprintf(string, "%d", number);
    return string;
}


unsigned char stringHeight(char** string) {
    // so sizeof returns effectively the area
    // and sizeof returns the width
    // area/width = height. Woo!
    if (string == NULL) {
        return 0; // To prevent division by zero
    }
    return sizeof(string)/sizeof(*string);
}

