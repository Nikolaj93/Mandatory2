#ifndef C-PROGRAMMING-EXAM_BINGO_H
#define C-PROGRAMMING-EXAM_BINGO_H

#include "card.h"

typedef struct bingo {
    Card *card; // cards in play
    int amount; // number of cards

    Card *cardLines;  // lines of cards
    int numLines;  // number of lines
    Card *cardBingos;  // bingo cards
    int numBingos;  // number of bingos
} Bingo;

#endif //C-PROGRAMMING-EXAM_BINGO_H
