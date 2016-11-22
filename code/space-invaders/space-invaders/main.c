//
//  main.c
//  space-invaders
//
//  Created by Illya Starikov on 11/10/16.
//  Copyright © 2016 Illya Starikov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "functions.h"
#include "game.h"
#include "constants.h"
#include "point.h"


int main(int argc, const char * argv[]) {
    Game game;
    CartesianPoint center;
    center.x = 25;
    
    char* header = NULL;
    char** footer = NULL, **gameboard = NULL;
    
    unsigned char i;
    
    initscr();
    
    initGame(&game);
    
    createHeader(&game, &header);
    drawShooter(center, &game, &footer);
    drawTheGame(&game, &gameboard, false);
    
    printw("%s\n", header);
    
    // This is really ugly.. but basically we start with the game height and then subt
    for (i = 0; i < game.height - 1 - sizeof(gunner)/sizeof(*gunner); i++) {
        printw("%s\n", gameboard[i]);
    }
    
    for (i = 0; i < stringHeight(footer) + 1; i++) {
        printw("%s\n", footer[i]);
    }

    for(;;) refresh();

    endwin();
    dealloc(&game, header, gameboard, footer);
}
