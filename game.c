#include "game.h"

static void menu()
{
    printf("**************************\n");
    printf("********Tic-Tac-Toe*******\n");
    printf("*********1.start**********\n");
    printf("*********0.exit***********\n");
    printf("**************************\n");
}

void choose()
{
    int input = 0;
    do
    {
        menu();
        printf("Please enter your choice: ");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            // game();
            printf("game start!\n");
            break;
        case 0:
            printf("Game over.\n");
            break;
        default:
            printf("Illegal enter, enter again.\n");
            break;
        }
    } while (input);
}

void initBoard(char board[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void showBoard(char board[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf(" ---");
        }
        printf("\n");
        for (int j = 0; j < COL; j++)
        {
            printf("| %c ", board[i][j]);
            if (j == COL - 1)
            {
                printf("|");
            }
        }
        printf("\n");

        if (i == ROW - 1)
        {
            for (int j = 0; j < COL; j++)
            {
                printf(" ---");
            }
            printf("\n");
        }
    }
}

void playerTurn(char board[ROW][COL])
{
    int x = 0;
    int y = 0;
    while (1)
    {
        printf("Please enter your location:");
        scanf("%d %d", &x, &y);
        if (board[x - 1][y - 1] == ' ')
        {
            board[x - 1][y - 1] = '*';
            break;
        }
        else
        {
            printf("illegal enter, enter again.\n");
        }
    }
}

void computerTurn(char board[ROW][COL])
{
    int x = 0;
    int y = 0;
    while (1)
    {
        x = rand() % 3;
        y = rand() % 3;
        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

char isWin(char board[ROW][COL], int *count)
{
    // player win: *
    // computer win: #
    // continue c
    // draw: d
    for (int i = 1; i < ROW - 1; i++)
    {
        for (int j = 1; j < COL - 1; j++)
        {
            if ((board[i][j] == board[i][j - 1] && board[i][j] == board[i][j + 1] && board[i][j] != ' ') || (board[i][j] == board[i - 1][j] && board[i][j] == board[i + 1][j] && board[i][j] != ' ') || (board[i][j] == board[i - 1][j - 1] && board[i][j] == board[i + 1][j + 1] && board[i][j] != ' ') || (board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i + 1][j - 1] && board[i][j] != ' '))
            {
                return board[i][j];
            }
        }
    }
    return --*count ? 'c' : 'd';
}

void game()
{
    srand((unsigned int)time(NULL));
    char board[ROW][COL] = {0};
    char symbol = 'c';
    int count = BOARDSPACE;

    initBoard(board);
    showBoard(board);

    while (symbol == 'c')
    {
        playerTurn(board);
        showBoard(board);
        if ((symbol = isWin(board, &count)) != 'c')
        {
            break;
        }

        computerTurn(board);
        showBoard(board);
        symbol = isWin(board, &count);
    }

    switch (symbol)
    {
    case '*':
        printf("Player win.\n");
        break;

    case '#':
        printf("Computer win.\n");
        break;

    case 'd':
        printf("The game drow.\n");
        break;
    }
}
