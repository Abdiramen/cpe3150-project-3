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


bool inBoundsOfGame(const Game* game, const CartesianPoint* point) {
    return point -> x >= 0 && point -> x < game -> width // the x is in bounds
   && point -> y >= 0 && point -> y < game -> height; // and the y is in bounds
}

int main(int argc, const char * argv[]) {
    Game game;
    CartesianPoint centerOfShooter;
    
    char* header = NULL;
    char** footer = NULL, **gameboard = NULL;
    
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    cbreak();
    
    keypad(stdscr, TRUE);
    
    initGame(&game);
    
    centerOfShooter.x = game.width / 2;
    centerOfShooter.y = game.height - 2;
    
    do {
        switch (getch()) {
            case KEY_LEFT:
                if (inBoundsOfGame(&game, &centerOfShooter)) {
                    centerOfShooter.x--;
                    clear();
                }
                break;
                
            case KEY_RIGHT:
                if (inBoundsOfGame(&game, &centerOfShooter)) {
                    centerOfShooter.x++;
                    clear();
                }
                break;
                
            case 'q':
                endwin();
                dealloc(&game, header, gameboard, footer);
                exit(0);
                break;
                
                
            default:
                createHeader(&game, &header);
                createShooter(centerOfShooter, &game, &footer);
                createGameboard(&game, &gameboard, false);
                draw(&game, &header, &gameboard, &footer);
                
                refresh();
                break;
        }
        
        

    } while (true);
    
    
}
