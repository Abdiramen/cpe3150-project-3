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
#include <sys/ioctl.h>

void initGame(Game* game) {
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    
    game -> width = w.ws_row;
    game -> height = w.ws_col;
    
    game -> gameBoard = malloc(game -> height * sizeof(unsigned char));
    for (int i = 0; i < game -> width; i++) {
        game -> gameBoard[i] = malloc(game -> width * sizeof(unsigned char));
    }
}


#include <string.h>
