#include <iostream>

using namespace std;

void printAirplaneSeating(char airplane[][4], int rows);
void getSeatSelection(int& row, char& column);
void reserveSeat(char airplane[][4], int rows, int row, char column);

int main() {
    char airplane[10][4];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            airplane[i][j] = char('A' + j);
        }
    }

    airplane[0][1] = 'X';
    airplane[2][3] = 'X';
    airplane[4][0] = 'X';

    printAirplaneSeating(airplane, 10);
    int row;
    char column;
    cout << "Above are the available seats (those not highlighted with an X)" << endl;
    getSeatSelection(row, column);
    reserveSeat(airplane, 10, row, column);
    char response;
    do {
        cout << "Do you want to make another reservation? (y/n): ";
        cin >> response;

        if (response == 'y' || response == 'Y') {
            printAirplaneSeating(airplane, 10);
            getSeatSelection(row, column);
            reserveSeat(airplane, 10, row, column);
        }
    }while (response == 'y' || response == 'Y');

    return 0;
}

void printAirplaneSeating(char airplane[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 4; j++) {
            cout << airplane[i][j] << " ";
        }
        cout << endl;
    }
}

void getSeatSelection(int& row, char& column) {
    cout << "Input the row number of the seat you want to reserve: ";
    cin >> row;
    cout << "Input the column letter of the seat you want to reserve: ";
    cin >> column;
}

void reserveSeat(char airplane[][4], int rows, int row, char column) {
    int columnIndex = column - 'A';

    while (row < 1 || row > 10 || columnIndex < 0 || columnIndex > 3) {
        cout << "Invalid input. Please enter a valid row number (1-10) and column letter (A-D)." << endl;
        getSeatSelection(row, column);
        columnIndex = column - 'A';
    }
    while (airplane[row - 1][columnIndex] == 'X') {
        cout << "Sorry, that seat is already reserved. Please choose another seat." << endl;
        getSeatSelection(row, column);
        columnIndex = column - 'A';
    }

    airplane[row - 1][columnIndex] = 'X';
    cout << "Seat reserved successfully!" << endl;
}