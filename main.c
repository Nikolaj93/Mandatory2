#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game/gameState.h"
#include "game/newGame.h"

void BINGO(void);

int main(void) {
    BINGO();
    return 0;
}
void BINGO(void) {
    char playing = 'Y';
    while (playing == 'Y' || playing == 'y') {
        srand(time(NULL)); // seed randomness

        Bingo bingo;
        Game game;
        newGame(&bingo, &game);

        // Regenerate?
        do {
            printf("Do you want to play again? <y/n>: ");
            scanf(" %c", &playing);
        } while ((playing != 'Y' && playing != 'y') &&
                 (playing != 'n' && playing != 'N'));
        if (playing == 'Y' || playing == 'y') system("cls");
    }
}
