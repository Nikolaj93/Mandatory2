#include <stdio.h>
#include <windows.h>
#include "showCards.h"

void showCards(Bingo bingo, Game game, Card *card, int ball, int num) {
    HANDLE cmd = GetStdHandle(STD_OUTPUT_HANDLE); // console output
    int i, j, k, n = 0; // iterators

    while (n < num) {
        printf("\nCard number: %d\n", card[n].id + 1);
        for (i = 0; i < ROWS; i++) {
            if (i == 0) {
                for (j = 0; j < COLUMNS; j++) {
                    if (j == 0) printf("%c%c%c%c%c%c", 201, 205, 205, 205, 205, 203);
                    else if (j == (COLUMNS - 1)) printf("%c%c%c%c%c", 205, 205, 205, 205, 187);
                    else printf("%c%c%c%c%c", 205, 205, 205, 205, 203);
                }
            }
            printf("\n");
            for (j = 0; j < COLUMNS; j++) {
                if (card[n].box[i][j] == -1) {
                    if (j == 0) printf("%c %c%c %c", 186, 219, 219, 186);
                    else printf(" %c%c %c", 219, 219, 186);
                } else {
                    if (j == 0) printf("%c", 186);
                    printf(" ");
                    // Check the box corresponding to the number that has come out, if there is a game
                    for (k = 0; k < ball; k++) {
                        if (card[n].box[i][j] == game.numbers[k])
                            SetConsoleTextAttribute(cmd, 164);
                    }
                    if (j == 0) printf("%2d", card[n].box[i][j]);
                    else printf("%2d", card[n].box[i][j]);
                    SetConsoleTextAttribute(cmd, 7);
                    printf(" %c", 186);
                }
            }
            printf("\n");
            if (i == (ROWS - 1)) {
                for (j = 0; j < COLUMNS; j++) {
                    if (j == 0) printf("%c%c%c%c%c%c", 200, 205, 205, 205, 205, 202);
                    else if (j == (COLUMNS - 1)) printf("%c%c%c%c%c", 205, 205, 205, 205, 188);
                    else printf("%c%c%c%c%c", 205, 205, 205, 205, 202);
                }
            } else {
                for (j = 0; j < COLUMNS; j++) {
                    if (j == 0) printf("%c%c%c%c%c%c", 204, 205, 205, 205, 205, 206);
                    else if (j == (COLUMNS - 1)) printf("%c%c%c%c%c", 205, 205, 205, 205, 185);
                    else printf("%c%c%c%c%c", 205, 205, 205, 205, 206);
                }
            }
        }
        printf("\n");
        n++;
    }
}