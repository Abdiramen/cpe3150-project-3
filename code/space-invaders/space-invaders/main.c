//
//  main.c
//  space-invaders
//
//  Created by Illya Starikov on 11/10/16.
//  Copyright © 2016 Illya Starikov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"
#include "game.h"
#include "constants.h"
#include "point.h"

int main(int argc, const char * argv[]) {
    Game game;
    CartesianPoint center;
    center.x = 4;
    
    char* header;
    char** footer;
    
    unsigned char i;
    
    initGame(&game);
    
    header = createHeader(&game);
    footer = drawShooter(center, &game);
    
    printf("%s\n", header);
    
    for (i = 0; i < strlen(*footer); i++) {
        printf("%s\n", footer[i]);
    }
    
    free(header);
    free(footer);
    free(game.gameBoard);
}
