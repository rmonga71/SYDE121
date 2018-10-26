/*
Name: Rohan Monga
Date: October 26, 2018
Course: SYDE 121
Assignment: Lab 5 Assignment 1
Exercise: Exercise #1
File Name: lab05_01.cpp
Project: 4x4 Tic Tac Toe
Purpose: Let two players play tic tac toe against each other

Outline steps:

1. Create a function that forms the initial 4x4 tic tac toe board.
2. Define functions that allow for the input of an x or an o on different positions on the board,
   using another function to alternate between turns.
3. Create a fourth function to check if a player has won the game.
4. If this has happened, return the team that has won along with a score counter.
5. Ask the players if they would like to play again.

To test my code, I ran through all the different possible scenarios. (x wins: diaganol both ways, vertically, horizontally)
and (o wins: diaganol both ways, vertically, horizontally), and ensured that the output was as exected. I also made sure to
look at the formatting of the board to ensure the spacing had been done correctly.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string board[4] [4] = {{"1", "2", "3", "4"}, {"5", "6", "7", "8"}, {"9", "10", "11", "12"}, {"13", "14", "15", "16"}}; //build initial board
string player = "X";

//--------------------------Function Definitions---------------------------------------

void print_board() {
    for (int row = 0; row < 4; row++){
            for (int column = 0; column < 4; column++){
                cout << setw(2) << board[row] [column] << " "; //spacing for the board
    }
    cout << endl;
}
}
//PURPOSE: prints the board
//INPUTS: the 4x4 board
//OUTPUTS: nothing to return


void input() {
    int player_move;
    cout << "Choose a tile for your move!";
    cin >> player_move;

    while (player_move > 16){ //prevents player from choosing an invalid position on the board
      cout << "Please enter a valid position!" << endl;
      break;
    }

    if (player_move == 1){
        board[0][0] = player;
    }else if (player_move == 2){
        board[0][1] = player;
    }else if (player_move == 3){
        board[0][2] = player;
    }else if (player_move == 4){
        board[0][3] = player;
    }else if (player_move == 5){
        board[1][0] = player;
    }else if (player_move == 6){
        board[1][1] = player;
    }else if (player_move == 7){
        board[1][2] = player;
    }else if (player_move == 8){
        board[1][3] = player;
    }else if (player_move == 9){
        board[2][0] = player;
    }else if (player_move == 10){
        board[2][1] = player;
    }else if (player_move == 11){
        board[2][2] = player;
    }else if (player_move == 12){
        board[2][3] = player;
    }else if (player_move == 13){
        board[3][0] = player;
    }else if (player_move == 14){
        board[3][1] = player;
    }else if (player_move == 15){
        board[3][2] = player;
    }else if (player_move == 16){
        board[3][3] = player;
    }
}

//PURPOSE: allows players to enter an x or an o in a position of their choice
//INPUTS: row, column, the current player (x or o)
//OUTPUTS: nothing to return

void change_player() {
  if (player == "X"){
    player = "O";
  }else{
    player = "X";
  }

}
//PURPOSE: alternates between players, (allows for turns)
//INPUTS: none
//OUTPUTS: nothing to return

string win_check() { //string board[4][4], const string& player

    // Checks for wins vertically
    for (int column = 0; column < 4; column++) {
        if (board[0][column] == player
         && board[1][column] == player
         && board[2][column] == player
         && board[3][column] == player) {
            return player;
        }
    }

    // Checks wins horizontally
    for (int row = 0; row < 4; row++) {
        if (board[row][0] == player
         && board[row][1] == player
         && board[row][2] == player
         && board[row][3] == player) {
            return player;
        }
    }

    // Checks for wins going from (0,0) to (3,3)
    if (board[0][0] == player
     && board[1][1] == player
     && board[2][2] == player
     && board[3][3] == player) {
        return player;
    }

    // Checks for wins going from (3,3) to (0,0)
    if (board[0][3] == player
     && board[1][2] == player
     && board[2][1] == player
     && board[3][0] == player) {
        return player;
    }

}
//PURPOSE: checks if a team has won the game, if not then continues the game
//INPUTS: board and current player
//OUTPUTS: the current player if they've won

bool play_again();

//PURPOSE: asks the user if they want to play again
//INPUTS: none
//OUTPUTS: returns true if they answer yes, returns false if no

//---------------------Main Function-----------------------------

int main() {

int score_x = 0;
int score_o = 0;
string answer;

cout << "Welcome to two player 4x4 Tic Tac Toe!\n" << endl;
cout << "Player X will go first, and player O second.\n" << endl;

print_board();
while (1)
{
  input();
  print_board();
  if (win_check() == "X") {
    cout << "Player X wins!" << endl;
    ++score_x;
    cout << "\nScore:\n";
    cout << "Player X: " << score_x << endl;
    cout << "Player O: " << score_o << endl;
    play_again();
    break;

  }else if (win_check() == "O") {
    cout << "Player O wins" << endl;
    ++score_o;
    cout << "\nScore:\n";
    cout << "Player X: " << score_x << endl;
    cout << "Player O: " << score_o << endl << endl;
    play_again();
    break;
  }
  change_player();

}



return 0;

}

bool play_again() {
    string answer;

    cout << endl;
    cout << "Would you like to play again? (Type yes/no): ";

    while(true) { //ask until they answer yes or no
        cin >> answer;
        if (answer == "Yes" || answer == "yes") {
            return true;
        } else if (answer == "No" || answer == "no") {
            return false;
        }

        cout << "Invalid input. Type \"yes\" or \"no\": "; //if the user doesn't answer yes or no
    }
}
