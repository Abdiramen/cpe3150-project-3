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

static const unsigned int STATE_CHANGE = 1500;

bool inBoundsOfGame(const Game* game, const CartesianPoint* point) {
    return point -> x >= 0 && point -> x < game -> width // the x is in bounds
   && point -> y >= 0 && point -> y < game -> height; // and the y is in bounds
}

int main(int argc, const char * argv[]) {
    Game game;
    
    char* header = NULL;
    char** footer = NULL, **gameboard = NULL;
    unsigned int i = 0;
    bool state = false;
    
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    cbreak();
    
    keypad(stdscr, TRUE);
    
    initGame(&game);
    
    game.gunner.center.x = game.width / 2;
    game.gunner.center.y = game.height - 2;
    
    do {
        switch (getch()) {
            case KEY_LEFT:
                if (inBoundsOfGame(&game, &game.gunner.center)) {
                    game.gunner.center.x--;
                }
                break;
                
            case KEY_RIGHT:
                if (inBoundsOfGame(&game, &game.gunner.center)) {
                    game.gunner.center.x++;
                }
                break;
                
            case ' ':
                game.gunner.playerDidShoot = true;
                game.gunner.playerShot = game.gunner.center;
                break;
                
            case 'q':
                endwin();
                dealloc(&game, header, gameboard, footer);
                exit(0);
                break;
                
                
            default:
                createHeader(&game, &header);
                createShooter(game.gunner.center, &game, &footer);
                createGameboard(&game, &gameboard, state);
                
                draw(&game, &header, &gameboard, &footer);
                
                break;
        }
        
        i++;
        if (i % STATE_CHANGE == 0) {
            state = state ? false : true; // You would think the compilment would work (~), but it doesn't
        }
        

    } while (true);
    
    
}
