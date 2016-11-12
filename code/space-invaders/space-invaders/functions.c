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
    
    game -> level = 0;
    game -> lives = 3;
    game -> score = 0;
    
    game -> gameBoard = malloc(game -> width * sizeof(char));
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
    const unsigned char width = sizeof(*asciiShooter);
    const unsigned char height = sizeof(asciiShooter) / width; // area = height*width => area/width = height
    
    char** shooterAscii = NULL;
    unsigned char i, j, shooterCounter;
    
    shooterAscii = malloc(game -> width * sizeof(char));
    for (int i = 0; i < height; i++) {
        shooterAscii[i] = malloc(height * sizeof(char));
    }
    
    for (j = 0; j < height; j++) {
        shooterCounter = 0;
        for (i = 0; i < game -> width; i++) {
            
            // the if determines if the shooter should be drawn, and it works like so:
            // if it's in the range of 1/2width on either side of the center, then it's a match
            // -1 because used sizeof for width calculation and that includes terminating character
            if (i + (width - 1)/2.0 >= center.x && i - (width - 1)/2.0 <= center.x ) {
                shooterAscii[j][i] = asciiShooter[j][shooterCounter];
                shooterCounter++;
            } else {
                shooterAscii[j][i] = ' ';
            }
        }
    }
    
    return shooterAscii;
}

int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    
    return base * power(base, exponent - 1);
}

char* numberToString(int number, char *string) {
    if(string == NULL) {
        return NULL;
    }
    
    sprintf(string, "%d", number);
    return string;
}



