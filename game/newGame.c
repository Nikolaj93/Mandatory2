#include <stdio.h>
#include "newGame.h"

void newGame(Bingo *bingo, Game *game) {
    int i; // iterator

    // Headboard
    printf("%c", 218);
    for (i = 0; i < 61; i++) { printf("%c", 196); }
    printf("%c\n", 191);
    printf("%c                    == BINGO GAME ==                    %c\n", 179, 179);
    printf("%c  (Author:  Nikolaj)  %c\n", 179, 179);
    printf("%c", 192);
    for (i = 0; i < 61; i++) { printf("%c", 196); }
    printf("%c\n\n", 217);

    // Check if it's the first game and show a welcome message or another
    static int nGame = 1;
    if (nGame == 1) {
        printf("Welcome to Bingo!\n");
        for (i = 0; i < 21; i++) { printf("%c", 196); }
        printf("\n");
    } else {
        printf("Welcome back to Bingo!\n");
        for (i = 0; i < 30; i++) { printf("%c", 196); }
        printf("\n");
    }
    nGame++;

    // Choose the game mode
    int gameMode;
    do {
        printf("Select game mode:\n");
        printf("  [1] Step by step.\n"
               "  [2] Full game.\n");
        printf("> ");
        scanf("%d", &gameMode);
    } while (gameMode != 1 && gameMode != 2);

    // Ask the user for the number of cards to play
    printf("\nIndicate the number of cards to play: ", 163);
    scanf("%d", &(bingo->amount));
    printf("\n");

    // Prepare the cards
    generateCards(bingo);

    // Game state
    gameState(bingo, game, gameMode);
}