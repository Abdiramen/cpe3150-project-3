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
    
    char* header;
    char** footer;
    
    CartesianPoint center;
    
    initGame(&game);
    header = createHeader(&game);
    footer = drawShooter(center, &game);
}
