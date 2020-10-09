#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <random>
#include "player.h"

using namespace std;

//decides if the game is active
//returns: true or false
bool menu() {
    bool menu = false;
    cout << "Would you like to begin the game?" << endl;
    cin >> menu;
    return menu;
};

//decides who's turn it is when game begins initially
//returns: a 1 or 1 for p1 or p2
int turn() {
    int turn = 0;
    turn = rand()%3 +1;
    return turn;
};


//is passed in the 2d array of board
//outputs the display of the board
void board(int board[7][7], int size = 7) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; i < size; j++) {
            cout << board[i][j] << " \n"[j == size-1];
        }
    }
}

//this is where all the main game logic will go
int main() {

//determine if game is playing
bool playing = menu();
if (playing) {
    //declare the valid board places
    int validBoard[7][7] = { {1,0,0,1,0,0,1},
                        {0,1,0,1,0,1,0},
                        {0,0,1,1,1,0,0},
                        {1,1,1,0,1,1,1},
                        {0,0,1,1,1,0,0},
                        {0,1,0,1,0,1,0},
                        {1,0,0,1,0,0,1} };

    //declare the board array & initialize all places to 0 
    int board[7][7] = {0};

    //create player objects
    player player1, player2;

    //randomize turn
    int playerTurn = turn();

    //begin the game turns in loop
    while (playing) {
        
    //if the turn is player1
    if (playerTurn == 1) {

    }

    //if the turn is player2
    else {

    }

    //print graph

    //check piece count
    if ((player1.pieceCount < 3) || (player2.pieceCount < 3)) {
        if (player1.pieceCount < 3) {
            //alert winner
            cout << "Player 2 has won, duces bitch!" << endl;
            
            //end game
            playing = false;
        }
        else {
            //alert winner
            cout << "Player 1 has won, duces bitch!" << endl;
            
            //end game
            playing = false;
        }
    }

    //next round
    cout << "Begin next turn round!" << endl;
    }
}
return 0;
}
