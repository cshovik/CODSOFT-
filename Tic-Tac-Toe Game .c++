#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe grid
void printGrid(const vector<vector<char>>& grid) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a player has won the game
bool checkWin(const vector<vector<char>>& grid, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; ++j) {
        if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == player) {
            return true;
        }
    }

    // Check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
        return true;
    }

    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
        return true;
    }

    return false;
}

// Function to check if the game ended in a draw
bool checkDraw(const vector<vector<char>>& grid) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to play the Tic-Tac-Toe game
void playGame() {
    vector<vector<char>> grid(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        // Print the grid
        printGrid(grid);

        // Get the player's move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || grid[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the grid with the player's move
        grid[row - 1][col - 1] = currentPlayer;

        // Check if the current player has won
        if (checkWin(grid, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the game ended in a draw
        if (checkDraw(grid)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    playGame();
    return 0;
}
