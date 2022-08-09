cmake_minimum_required(VERSION 3.19)
project(C-Programming-Exam C)

set(CMAKE_C_STANDARD 99)

add_executable(C-Programming-Exam main.c game/newGame.c game/newGame.h card/showCards.c card/showCards.h game/gameState.c game/gameState.h card/generateCards.c card/generateCards.h utils/bingo.h utils/card.h utils/game.h)
