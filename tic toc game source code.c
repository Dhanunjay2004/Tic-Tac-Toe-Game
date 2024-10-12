#include <stdio.h>

char board[3][3]; // 3x3 board
char currentPlayer = 'X'; // Starting player

void printBoard() {
    for (int i = 0; i < 3; i++) {
        printf("%c %c %c\n", board[i][0], board[i][1], board[i][2]);
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
            return 1;
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
        return 1;
    return 0;
}

int main() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    
    for (int turn = 0; turn < 9; turn++) {
        printBoard();
        int row, col;
        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            if (checkWin()) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                return 0;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
        } else {
            printf("Invalid move! Try again.\n");
            turn--; // Repeat turn
        }
    }
    printBoard();
    printf("It's a draw!\n");
    return 0;
}
