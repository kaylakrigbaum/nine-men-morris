#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#ifndef PLAYER_H
#define PLAYER_H

//main declarations of player class
class player {
    public:
        int player;
        int pieceCount;
        int placedPieces;
        int phase;
        void move ();
};

#endif
