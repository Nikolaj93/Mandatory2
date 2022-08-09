#ifndef C-PROGRAMMING-EXAM_CARD_H
#define C-PROGRAMMING-EXAM_CARD_H

#define ROWS 3
#define COLUMNS 9

typedef struct card {
    int box[ROWS][COLUMNS];
    int id;
} Card;

#endif //C-PROGRAMMING-EXAM_CARD_H
