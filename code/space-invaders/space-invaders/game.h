 //
//  game.h
//  space-invaders
//
//  Created by Illya Starikov on 11/10/16.
//  Copyright © 2016 Illya Starikov. All rights reserved.
//

#ifndef game_h
#define game_h

typedef struct Game {
    unsigned char lives, level;
    int width, height;
    char** gameBoard;
} Game;

#endif /* game_h */
