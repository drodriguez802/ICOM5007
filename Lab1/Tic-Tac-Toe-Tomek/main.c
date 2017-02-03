#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Winner defines the winner of the match, -1 if X O won, 1 if X did and 0 if it was a draw
int winner = 0;
int x = -1;
int y = -1;
bool dotExists = false;

int horizontal(char board[4][4]) {
    for (int i = 0; i < 4; i++) {
        if (board[i][0] != '.' && (board[i][0] == board[i][1])&&(board[i][1] == board[i][2])&&(board[i][2] == board[i][3])) {
            return board[i][0] == 'O' ? 1 : -1;
        }
        char token = board[i][0] != 'T' ? board[i][0] : board[i][3];
        bool wereSame = true;
        for (int j = 0; j < 4; j++) {
            if ((token != board[i][j] && board[i][j] != 'T') || token == '.') {
                wereSame = false;
            }
            if (board[i][j] == 'T') {
                x = i;
                y = j;
            }
            if (board[i][j] == '.') {
                dotExists = true;
            }
        }
        if (wereSame) {
            return token == 'O' ? 1 : -1;
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    int caseNumber = 0;
    printf("Enter the number of students to input: \n");
    scanf("%d", &caseNumber);
    char board[4][4];
    FILE *myBoard;
    myBoard = fopen("board.txt", "r");
    int k;
    int cNum = caseNumber;
    for(k=0;k<cNum;k++){
        int i;
        for (i = 0; i < 4; i++)
        {
            int j;
            for(j = 0; j<=4;j++){
                fscanf(myBoard, "%1c", &board[i][j]);
            }
        }
        
     mainFind(board, k+1);
    }
    


    return 0;
}

void mainFind(char board[4][4], int caseNumber) {
    x = -1;
    y = -1;
    int winner;
    
    if ((winner = horizontal(board)) != 0) {

        if (winner == -1) {
            printf("Case #%d: X won\n", caseNumber);
        } else {
            printf("Case #%d: O won\n", caseNumber);
        }
    } else if ((winner = diagonal(board)) != 0) {

        if (winner == -1) {
            printf("Case #%d: X won\n", caseNumber);
        } else {
            printf("Case #%d: O won\n", caseNumber);
        }
    } else if ((winner = vertical(board)) != 0) {
        if (winner == -1) {
            printf("Case #%d: X won\n", caseNumber);
        } else {
            printf("Case #%d: O won\n", caseNumber);
        }
    } else {
        if (dotExists) {
            printf("Case #%d: Game has not completed\n", caseNumber);
        } else {
            printf("Case #%d: Draw\n", caseNumber);
        }
    }
}

int vertical(char board[4][4]) {
    if (x == -1) {
        for (int i = 0; i < 4; i++) {
            if ((board[0][i] != '.')&&(board[0][i] == board[1][i])&&(board[1][i] == board[2][i])&&(board[2][i] == board[3][i])) {
                return board[0][i] == 'O' ? 1 : -1;
            }
        }
        return 0;
    } else {
        for (int i = 0; i < 4; i++) {
            char token = board[0][i] != 'T' ? board[0][i] : board[3][i];
            bool found = true;
            for (int j = 0; j < 4 && found; j++) {
                if ((token != board[j][i] && board[j][i] != 'T') || token == '.') {
                    found = false;
                }
            }
            if (found) {
                return token == 'O' ? 1 : -1;
            }
        }
        return 0;
    }
}

int diagonal(char board[4][4]) {
    //No T was found so only way diagonals have a solution if its they all are equal
    if (x == -1) {
        if (board[0][0] == board[1][1]&& (board[1][1] == board[2][2]) && board[2][2] == board[3][3] && board[3][3] != '.') {
            return board[3][3] == 'O' ? 1 : -1;
        } else if (board[0][3] == board[1][2] && board[2][1] == board[3][0] && board[3][0] != '.') {
            return board[3][0] == 'O' ? 1 : -1;
        }
    }//Iterate through diagonals until a solution is found if any
    else {
        bool found = true;
        bool leftToRight = false;
        int index = 0;
        int first = 0;
        int second = 0;

        while (index < 2) {
            char token;
            if (!leftToRight) {
                token = board[0][0] == 'T' ? board[3][3] : board[0][0];
            } else {
                token = board[0][3] == 'T' ? board[3][0] : board[0][3];
            }
            //From 00 to 33
            while (first < 4) {

                if ((token != board[first][second] && board[first][second] != 'T') || token == '.') {
                    found = false;
                    break;
                }
                if (leftToRight) {
                    first++;
                    second--;
                } else {
                    first++;
                    second++;
                }
            }
            if (found) {
                return token == 'O' ? 1 : -1;
            }
            found = true;
            leftToRight = true;
            first = 0;
            second = 3;
            index++;
        }
    }
    return 0;
}