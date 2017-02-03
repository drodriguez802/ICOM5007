#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * 
 */
int m = 0;
int n = 0;

int findWord(char board[m][n], char first, char word[], int wLength, int x, int y) {
    int length = wLength;
    //East
    if ((y + length - 1) < n) {
        bool solution = true;
        int index = 0;
        int i;
        for (i = y; i < m && index < length; i++) {
            if (word[index] != board[x][i]) {
                solution = false;
            }
            index++;
        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //South
    if ((x + length - 1) < m) {
        bool solution = true;
        int index = 0;
        int i;
        for (i = x; i < m && index < length; i++) {
            if (word[index] != board[i][y]) {
                solution = false;
            }
            index++;
        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //SouthEast
    if ((x + length - 1) < m && (y + length - 1) < n) {
        bool solution = true;
        int index = 0;
        int i;
        int yDelta = y;
        for (i = x; i < m && index < length; i++) {
            if (word[index] != board[i][yDelta] && yDelta < n) {
                solution = false;
            }
            yDelta++;
            index++;

        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //NorthEast
    if ((x - length + 1) >= 0 && (y + length - 1) < n) {
        bool solution = true;
        int xDelta = x;
        int index = 0;
        int i;
        for (i = y; i < m && index < length; i++) {
            if (word[index] != board[xDelta][i]) {
                solution = false;
            }
            index++;
            xDelta--;
        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //NORTH
    if ((x - length + 1) >= 0) {
        bool solution = true;
        int index = 0;
        int i;
        for (i = x; i < m && index < length; i--) {
            if (word[index] != board[i][y]) {
                solution = false;
            }
            index++;
        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //Northwest
    if ((x - length + 1) >= 0 && (y - length + 1) >= 0) {
        bool solution = true;
        int xDelta = x;
        int index = 0;
        int i;
        for (i = y; i < m && index < length; i--) {
            if (word[index] != board[xDelta][i]) {
                solution = false;
            }
            index++;
            xDelta--;
        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //wEST
    if ((y - length + 1) >= 0) {
        bool solution = true;
        int index = 0;
        int i;
        for (i = y; i < m && index < length; i--) {
            if (word[index] != board[x][i]) {
                solution = false;
            }
            index++;
        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }
    //SouthwEST
    if ((x + length - 1) < m && (y - length + 1) >= 0) {
        bool solution = true;
        int index = 0;
        int i;
        int yDelta = y;
        for (i = x; i < m && index < length; i++) {
            if (word[index] != board[i][yDelta]) {
                solution = false;
            }
            yDelta--;
            index++;

        }
        if (solution) {
            int atr[] = {x, y};
            return atr;
        }
    }

    int atr[] = {-1, -1};
    return atr;
}

int main(int argc, char** argv) {
    FILE *myCrosswords;
    FILE *myWords;
    myCrosswords = fopen("board.txt", "r");
    myWords = fopen("words.txt", "r");
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\n");
    m = a;
    n = b;
    char board[a][b];
    int w = 0;
    scanf("%d", &w);
    char words[w][20];
    int f = 0;
    for (f = 0; f < w; f++) {
        int l;
        for (l = 0; l < 20; l++) {
            words[f][l] = NULL;
        }
    }
    int i;
    for (i = 0; i < a; i++) {
        int j;
        for (j = 0; j <= b; j++) {
            char tC;
            fscanf(myCrosswords, "%1c", &tC);
            if (tC > 90) {
                board[i][j] = tC - 32;
            } else {
                board[i][j] = tC;
            }
        }
    }
    for (i = 0; i < w; i++) {
        int p = 0;
        char tC = '0';
        while (p < 20 && tC != '\n' && tC != '\0' && tC != '*') {
            fscanf(myWords, "%1c", &tC);
            if (tC >= 97 && tC <= 122 && tC != '\n' && tC != '\0') {
                words[i][p] = tC - 32;
            } else if (tC >= 65 && tC <= 90 && tC != '\n' && tC != '\0') {
                words[i][p] = tC;
            }
            p++;
        }
        bool notFound = true;
        int k;
        for (k = 0; k < m && notFound; k++) {
            int q;
            for (q = 0; q < n && notFound; q++) {
                if (words[i][0] == board[k][q]) {
                    int * test = findWord(board, board[k][0], words[i], strlen(words[i]), k, q);
                    if (test[0] != -1) {
                        printf("%d %d\n", test[0] + 1, test[1] + 1);
                        notFound = false;
                    }
                }
            }
        }

    }


    return 0;
}