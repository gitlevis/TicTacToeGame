#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
#define BOARDSPACE ROW*COL

void choose();

void game();

void showBoard(char board[ROW][COL]);
