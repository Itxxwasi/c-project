
#include <iostream>
#include <limits>
using namespace std;

const int BOARD_SIZE = 3;

char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

struct Player {
    string name;
    char symbol;                                                     // STARTING FROM 26/12/2023    END 28/12/2023 THIS GAME COMPLEATED AFTER 16H CONSISTENT WORK 
};

Player players[2];

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cout << board[i][j];
            if (j < BOARD_SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < BOARD_SIZE - 1) cout << "---------" << endl;
    }
}

bool isMoveValid(int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

bool isBoardFull() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool checkWin(char playerSymbol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
            return true;
        if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)
            return true;
    }

    if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
        return true;
    if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
        return true;

    return false;
}

void makeMove(Player& currentPlayer, int row, int col) {
    board[row][col] = currentPlayer.symbol;
}

void clearBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void initializePlayers() {
    for (int i = 0; i < 2; i++) {
        cout << "Enter name for Player " << i + 1 << ": ";
        cin >> players[i].name;
        players[i].symbol = (i == 0) ? 'X' : 'O';
    }
}

int main() {
    int rounds;
    cout << "Enter the number of rounds: ";
    cin >> rounds;

    initializePlayers();

    for (int round = 1; round <= rounds; round++) {
        clearBoard();
        cout << "\nRound " << round << "!\n";

        int currentPlayerIndex = 0;

        while (true) {
            printBoard();

            Player& currentPlayer = players[currentPlayerIndex];

            int row, col;
            cout << currentPlayer.name << "'s turn (" << currentPlayer.symbol << "):\n";
            cout << "Enter the row number (0, 1, or 2): ";
            cin >> row;
            cout << "Enter the column number (0, 1, or 2): ";
            cin >> col;

            if (cin.fail() || !isMoveValid(row, col)) {
                cout << "Invalid input. Please enter valid row and column numbers.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            makeMove(currentPlayer, row, col);

            if (checkWin(currentPlayer.symbol)) {
                printBoard();
                cout << currentPlayer.name << " wins Round " << round << "!\n";
                break;
            } else if (isBoardFull()) {
                printBoard();
                cout << "It's a draw in Round " << round << "!\n";
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % 2;
        }
    }

    cout << "\nGame Over! Thanks for playing.\n";

    return 0;
}


//This version includes multiple rounds, player names, input validation, and improved structure. Players take turns entering their moves, and the game announces the winner or a draw at the end of each round.A game by wasitech
