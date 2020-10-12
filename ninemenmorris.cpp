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
    cout << endl << endl << endl;
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


//takes in game board and model of valid board. outputs game board based on which nodes in the valid board are legal nodes
void displayBoard(vector<vector<int>> board, vector<vector<int>> validBoard, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << i + 1 << "   ";
        for (int j = 0; j < cols; j++) {
            if (validBoard[i][j] == 1)
                cout << board[i][j] << " ";
            else
                cout <<  "  ";
        }
        cout << "\n";
    }

    cout << "    a b c d e f g" << endl << endl;
}

//stage 1: players place their pieces.
void placementStage(Player& white, Player& black, vector<vector<int>> board, vector<vector<int>> validBoard)
{
    string currentPlayer = "white";
    int currentTurnNum = 1;
    string move;
    while (white.placedPieces < 9 || black.placedPieces < 9)
    {
        cout << "It is " << currentPlayer << "'s turn. Enter a location to place a piece: \n";
        cin >> move;
        cout << endl << endl;

        //convert column letter to index
        char colChar = move[0];

        int colNum = int(colChar) - 97;
        int rowNum = move[1] - '0' - 1;

        //check if move is legal
        if (colNum < validBoard.size() && rowNum < validBoard.size() && validBoard[rowNum][colNum] == 1 && board[rowNum][colNum] == 0)
        {
            board[rowNum][colNum] = currentTurnNum;
            //check for mill
            if (currentTurnNum == 1)
            {
                white.placedPieces += 1;
                currentPlayer = "black";
                currentTurnNum = 2;
            }
            else
            {
                black.placedPieces += 1;
                currentPlayer = "white";
                currentTurnNum = 1;
            }

            displayBoard(board, validBoard, 7, 7);
        }
        else
        {
            cout << "Invalid location" << endl;
            continue;
        }

    }
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
            displayBoard(board, validBoard, 7, 7);
        
            //if the turn is player1
            if (playerTurn == 1) {
                placementStage(player1, player2, board, validBoard);
            }

            //if the turn is player2
            else {
                placementStage(player2, player1, board, validBoard);
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
