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
    
    game -> gameBoard = malloc(game -> height * sizeof(char));
    for (int i = 0; i < game -> width; i++) {
        game -> gameBoard[i] = malloc(game -> width * sizeof(char));
    }
}

char* createHeader(const Game *game) {
    static char* headerLine = NULL;
    unsigned char i, workingSize = game -> width; // working size is to keep track how much room is left for the header line
    char tempString[2];
    
    headerLine = (char*)malloc(game -> width * sizeof(char));
    
    if (workingSize > strlen(NAME)) {
        strcat(headerLine, NAME);
        workingSize -= strlen(NAME);
    }
    
    if (workingSize > strlen(tempString) + 1) { // +1 because extra life
        strcat(headerLine, LIVES);
        strcat(headerLine, numberToString(game -> lives, tempString));
       
    }
    
    
    return headerLine;
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



