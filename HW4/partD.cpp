#include <iostream>

using namespace std;

void printTicTacToe(char board[3][3]);
void checkWin(char board[3][3]);

int main() {
    char TicTacToe[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    
    cout << "Let's play tic-tac-toe! Player 1 is X and Player 2 is O." << endl;
    
    printTicTacToe(TicTacToe);

    for (int i = 0; i < 9; i++) {
        int player = i % 2 + 1;
        char mark = 'X';
        if (player == 2) {
            mark = 'O';
        }
        int move;

        cout << "Player " << player << ", enter the number of the cell where you want to place your mark: ";
        cin >> move;

        while (move < 1 || move > 9) {
            cout << "Invalid input. Please enter a number between 1 and 9: ";
            cin >> move;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        while (TicTacToe[row][col] == 'X' || TicTacToe[row][col] == 'O') {
            cout << "That cell is already occupied. Please choose another cell: ";
            cin >> move;
            row = (move - 1) / 3;
            col = (move - 1) % 3;
        }

        TicTacToe[row][col] = mark;
        printTicTacToe(TicTacToe);
        checkWin(TicTacToe);
        if (i == 8) {
            cout << "It's a draw!" << endl;
        }
    }
    return 0;
}

void printTicTacToe(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
        }
        cout << "\n";
        cout << endl;
    }
}

void checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            cout << "Player " << board[i][0] << " wins!" << endl;
            exit(0);
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            cout << "Player " << board[0][i] << " wins!" << endl;
            exit(0);
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        cout << "Player " << board[0][0] << " wins!" << endl;
        exit(0);
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cout << "Player " << board[0][2] << " wins!" << endl;
        exit(0);
    }
}