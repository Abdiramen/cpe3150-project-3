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
    
    char* header = NULL;
    char** footer = NULL, **gameboard = NULL;
    
    unsigned char input = '0';
    
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    cbreak();
    
    initGame(&game);
    center.x = game.width / 2;

    do {
        input = getch();
        
        createHeader(&game, &header);
        createShooter(center, &game, &footer);
        createGameboard(&game, &gameboard, false);
        
        draw(&game, &header, &gameboard, &footer);
        
    } while (input != 'q');
    
    endwin();
    dealloc(&game, header, gameboard, footer);
}
