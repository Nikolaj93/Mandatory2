#include <stdio.h>
#include <stdlib.h>
#include "gameState.h"

void gameState(Bingo *bingo, Game *game, int gameMode) {
    int i, j, k, n, x, y; // iterators
    int bool_L, bool_B;
    int counter1 = 0, counter2 = 0; // auxiliary counters

    // Initialize todo a 0
    int shuffle = 0; // counter numbers shuffle
    int ball = 0;
    int card_lines = 0, card_bingos = 0;
    bingo->numLines = 0;
    bingo->numBingos = 0;

    // Assign dynamic memory
    game->numbers = (int *) malloc(sizeof(int));
    bingo->cardLines = (Card *) malloc((bingo->amount * 3) * sizeof(Card));
    bingo->cardBingos = (Card *) malloc((bingo->amount * 3) * sizeof(Card));

    while (bingo->numBingos == 0) {
        // Dynamic memory reallocation
        game->numbers = (int *) realloc(game->numbers, (shuffle + 1) * sizeof(int));

        // Randomly shuffle(no repetition)
        ball = rand() % (90 + 1 - 0) + 0;
        if (shuffle != 0) {
            for (k = 0; k < shuffle; k++) {
                if (ball == game->numbers[k]) {
                    ball = rand() % (90 + 1 - 0) + 0;
                    k = 0;
                }
            }
        }
        game->numbers[shuffle] = ball;

        // Check if there has been any line or bingo
        bingo->numLines = 0;
        bingo->numBingos = 0;
        card_lines = 0;
        card_bingos = 0;
        for (n = 0; n < bingo->amount; n++) {
            counter2 = 0;
            bool_L = 0;
            bool_B = 0;
            for (i = 0; i < 3; i++) {
                counter1 = 0;
                for (j = 0; j < 9; j++) {
                    for (k = 0; k < (shuffle + 1); k++) {
                        if ((bingo->card[n].box[i][j] != -1) &&
                            (bingo->card[n].box[i][j] == game->numbers[k]))
                            counter1++;
                    }
                }
                // line: All checked boxes in the same row (5)
                if (counter1 == 5) {
                    bingo->numLines++;
                    for (x = 0; x < ROWS; x++) {
                        for (y = 0; y < COLUMNS; y++) {
                            bingo->cardLines[card_lines].box[x][y] = bingo->card[n].box[x][y];
                        }
                    }
                    bingo->cardLines[card_lines].id = bingo->card[n].id;

                    if (bool_L == 0) {
                        card_lines++;
                    }
                    bool_L = 1;
                }

                // bingo: All marked boxes on the same card (15) <-> 3 lines
                counter2 += counter1;
                if (counter2 == (5 * 3)) {
                    bingo->numBingos++;
                    for (x = 0; x < ROWS; x++) {
                        for (y = 0; y < COLUMNS; y++) {
                            bingo->cardBingos[card_bingos].box[x][y] = bingo->card[n].box[x][y];
                        }
                    }
                    bingo->cardBingos[card_bingos].id = bingo->card[n].id;

                    if (bool_B == 0) {
                        card_bingos++;
                    }
                    bool_B = 1;
                }
            }
        }

        if (gameMode == 1 || (gameMode == 2 && bingo->numBingos != 0)) {
            // Show all cards
            printf("(%d) Next number is: %d\n", (shuffle + 1), game->numbers[shuffle]);
            for (i = 0; i < 16; i++) { printf("%c", 196); }
            showCards(*bingo, *game, bingo->card, (shuffle + 1), bingo->amount);

            // Show the cards with line and bingo
            if (card_lines > 0) {
                printf("\n");
                for (k = 0; k < 19; k++) { printf("%c", 196); }
                printf("%cLINE%c", 180, 195);
                for (k = 0; k < 20; k++) { printf("%c", 196); }

                showCards(*bingo, *game, bingo->cardLines, (shuffle + 1), card_lines);
            }
            if (card_bingos > 0) {
                printf("\n");
                for (k = 0; k < 19; k++) { printf("%c", 196); }
                printf("%cBINGO!%c", 180, 195);
                for (k = 0; k < 20; k++) { printf("%c", 196); }

                showCards(*bingo, *game, bingo->cardBingos, (shuffle + 1), card_bingos);
            }

            // Shows the summary of lines and bingo halls
            printf("%c", 218);
            for (i = 0; i < 44; i++) { printf("%c", 196); }
            printf("%c\n", 191);
            printf("%cNumber of lines: %2d "
                   "                "
                   "Number of bingos: %d%c\n", 179, bingo->numLines, bingo->numBingos, 179);
            printf("%c", 192);
            for (i = 0; i < 44; i++) { printf("%c", 196); }
            printf("%c\n", 217);

            /* Shows the balls that have come out */
            printf(" Numbers drawn:");
            for (i = 0, j = 0; i < (shuffle + 1); i++, j++) {
                if (j == 16) {
                    printf("\n");
                    j = -1;
                }
                printf(" (%d)", game->numbers[i]);
            }
            printf("\n\n");

            /* Wait for user intervention to continue */
            system("pause");
            printf("\n\n");
        }
        shuffle++;
    }
    // Free up dynamic memory
    free(bingo->cardLines);
    free(bingo->cardBingos);
    free(game->numbers);
    free(bingo->card);
}