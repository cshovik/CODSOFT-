#include <iostream>
#include <vector>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;

// Function to display the seating arrangement
void displaySeatingChart(const vector<vector<char>>& seatingChart) {
    cout << "Seating Chart:\n";
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << seatingChart[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a seat is available
bool isSeatAvailable(vector<vector<char>>& seatingChart, int row, int col) {
    return seatingChart[row][col] == 'O';
}

// Function to book a seat
void bookSeat(vector<vector<char>>& seatingChart, int row, int col) {
    seatingChart[row][col] = 'X';
}

// Function to calculate the total cost
double calculateTotalCost(int numSeats) {
    const double TICKET_PRICE = 10.0;
    return numSeats * TICKET_PRICE;
}

int main() {
    // Initialize the seating chart
    vector<vector<char>> seatingChart(NUM_ROWS, vector<char>(NUM_COLS, 'O'));

    int numSeats;
    cout << "Welcome to the Movie Ticket Booking System\n";
    cout << "Enter the number of seats you want to book: ";
    cin >> numSeats;

    // Display initial seating arrangement
    displaySeatingChart(seatingChart);

    // Seat selection loop
    for (int i = 0; i < numSeats; ++i) {
        int row, col;
        bool validSelection = false;

        while (!validSelection) {
            cout << "Enter the row and column of seat " << (i + 1) << " (e.g., 1 2): ";
            cin >> row >> col;

            if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
                cout << "Invalid seat selection. Please try again.\n";
            } else if (!isSeatAvailable(seatingChart, row - 1, col - 1)) {
                cout << "Seat not available. Please select a different seat.\n";
            } else {
                validSelection = true;
                bookSeat(seatingChart, row - 1, col - 1);
            }
        }
    }

    // Display updated seating arrangement
    displaySeatingChart(seatingChart);

    // Calculate and display the total cost
    double totalCost = calculateTotalCost(numSeats);
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}
