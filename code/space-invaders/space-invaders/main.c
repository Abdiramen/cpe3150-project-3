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

int main(int argc, const char * argv[]) {
    Game game;
    char* header;
    
    initGame(&game);
    header = createHeader(&game);
    printf("%s\n", header);
}
