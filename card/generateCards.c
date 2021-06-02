#include <stdlib.h>
#include "generateCards.h"

void generateCards(Bingo *bingo) {
    int i, j, n; // iterators

    // Prepare as many cards as the user has requested
    bingo->card = (Card *) malloc(bingo->amount * sizeof(Card));

    // Construct the cards
    for (n = 0; n < bingo->amount; n++) {
        // Fill in the boxes
        for (j = 0; j < 9; j++) {
            do {
                for (i = 0; i < 3; i++) {
                    bingo->card[n].box[i][j] = rand() % (9 + 1 - 0) + 0;
                    switch (j) {
                        case 1:
                            bingo->card[n].box[i][j] += 10;
                            break;
                        case 2:
                            bingo->card[n].box[i][j] += 20;
                            break;
                        case 3:
                            bingo->card[n].box[i][j] += 30;
                            break;
                        case 4:
                            bingo->card[n].box[i][j] += 40;
                            break;
                        case 5:
                            bingo->card[n].box[i][j] += 50;
                            break;
                        case 6:
                            bingo->card[n].box[i][j] += 60;
                            break;
                        case 7:
                            bingo->card[n].box[i][j] += 70;
                            break;
                        case 8:
                            bingo->card[n].box[i][j] += (80 + 1);
                            break;
                    }
                }
            } while (bingo->card[n].box[0][j] == bingo->card[n].box[1][j] ||
                     bingo->card[n].box[1][j] == bingo->card[n].box[2][j] ||
                     bingo->card[n].box[0][j] == bingo->card[n].box[2][j] ||
                     bingo->card[n].box[0][j] > bingo->card[n].box[1][j] ||
                     bingo->card[n].box[1][j] > bingo->card[n].box[2][j]);
        }
        // Create gaps
        int gap, pos;
        for (i = 0; i < 3; i++) {
            gap = 0, pos = 0;
            while (gap < 4) {
                pos = rand() % (8 + 1 - 0) + 0;                   // Generate random position
                if (bingo->card[n].box[i][pos] != -1) {     // Check if it has not been generated before
                    bingo->card[n].box[i][pos] = -1;        // Save the position in the box
                    gap++;
                }
            }
        }
        // Assign an identifier (id) to each card
        bingo->card[n].id = n;
    }
}
