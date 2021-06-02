#ifndef MANDATORY2_CARD_H
#define MANDATORY2_CARD_H

#define ROWS 3
#define COLUMNS 9

typedef struct card {
    int box[ROWS][COLUMNS];
    int id;
} Card;

#endif //MANDATORY2_CARD_H
