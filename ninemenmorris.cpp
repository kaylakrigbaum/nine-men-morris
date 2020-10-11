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
    char menu;
    cout << "Would you like to begin the game?" << endl;
    cin >> menu;
    if (toupper(menu) == 'Y')
        return true;
    return false;
};

//decides who's turn it is when game begins initially
//returns: a 1 or 2 for p1 or p2
int selectPlayerTurns() {
    int turn = 0;
    turn = 1 + (rand() % static_cast<int>(2 - 1 + 1));
    return turn;
};


//is passed in the 2d array of board
//outputs the display of the board
void displayBoard(vector<vector<int>> board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void placementStage(Player white, Player black, int board)
{
    return;
}

//this is where all the main game logic will go
int main() {

    //determine if game is playing
    bool playing = menu();
    if (playing) {
        //declare the valid board places
        vector<vector<int>> validBoard = {
            {1,0,0,1,0,0,1},
            {0,1,0,1,0,1,0},
            {0,0,1,1,1,0,0},
            {1,1,1,0,1,1,1},
            {0,0,1,1,1,0,0},
            {0,1,0,1,0,1,0},
            {1,0,0,1,0,0,1} 
        };

        //declare the board array & initialize all places to 0 
        vector<vector<int>> board(7, vector<int>(7, 0));
            

        //create player objects
        Player player1, player2;

        //randomize turn
        int playerTurn = selectPlayerTurns();

        //begin the game turns in loop
        while (playing) {
            displayBoard(validBoard, 7, 7);
        
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
