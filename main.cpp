// main.cpp
#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
 vector<vector<char>> board(SIZE, vector<char>(SIZE, '-'));
 char currentPlayer = 'X';

 void printBoard() {
     for (const auto& row : board) {
         for (char cell : row) {
             cout << cell << " ";
         }
         cout << endl;
     }
 }

 bool isWinner(char player) {
     // Check rows
     for (int i = 0; i < SIZE; ++i) {
         if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
             return true;
         }
     }

     // Check columns
     for (int i = 0; i < SIZE; ++i) {
         if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
             return true;
         }
     }

     // Check diagonals
     if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
         return true;
     }
     if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
         return true;
     }

     return false;
 }

 bool isBoardFull() {
     for (const auto& row : board) {
         for (char cell : row) {
             if (cell == '-') {
                 return false;
             }
         }
     }
     return true;
 }

 void makeMove() {
     int row, col;
     while (true) {
         cout << "Player " << currentPlayer << ", enter your move (row and column): ";
         cin >> row >> col;
         if (row < 1 || row > SIZE || col < 1 || col > SIZE) {
             cout << "Invalid move. Please try again." << endl;
             continue;
         }
         row -= 1; // Adjust for 0-based index
         col -= 1; // Adjust for 0-based index
         if (board[row][col] == '-') {
             board[row][col] = currentPlayer;
             break;
         } else {
             cout << "Cell already taken. Please try again." << endl;
         }
     }
 }

 int main() {
     cout << "Tic Tac Toe Game" << endl;
     cout << "Enter names for players X and O:" << endl;
     string playerX, playerO;
     cout << "Player X: ";
     cin >> playerX;
     cout << "Player O: ";
     cin >> playerO;

     while (true) {
         printBoard();
         makeMove();
         if (isWinner(currentPlayer)) {
             printBoard();
             cout << "Player " << currentPlayer << " wins!" << endl;
             break;
         }
         if (isBoardFull()) {
             printBoard();
             cout << "It's a draw!" << endl;
             break;
         }
         currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
     }

     return 0;
 }
