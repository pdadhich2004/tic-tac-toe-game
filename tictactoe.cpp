#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

// Print the board
void printBoard() {
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " -----------" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " -----------" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

// Check if a player has won
bool checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

// Main game loop
void playGame() {
    int move;
    bool gameWon = false;

    for (int turn = 0; turn < 9 && !gameWon; turn++) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Convert move to board coordinates
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        // Check if the cell is free
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;  // Make the move
            gameWon = checkWin();  // Check if the move caused a win

            if (gameWon) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  // Switch players
            }
        } else {
            cout << "Invalid move, try again." << endl;
            turn--;  // Redo the turn
        }
    }

    if (!gameWon) {
        printBoard();
        cout << "It's a draw!" << endl;
    }
}

int main() {
    playGame();
    return 0;
}
