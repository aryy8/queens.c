#include <stdio.h>
#define N 5

void printBoard(int board[N][N]);
int isSafe(int board[N][N], int row, int col);
int placeQueen(int board[N][N], int row, int col);

int main()
{
    int board[N][N] = {0};
    int row, col, queensPlaced = 0;

    while (queensPlaced < N)
    {
        printBoard(board);
        printf("Enter row and column to place a queen (0-indexed): ");
        scanf("%d %d", &row, &col);

        if (placeQueen(board, row, col))
        {
            queensPlaced++;
        }
        else
        {
            printf("Invalid position! Try again.\n");
        }
    }

    printBoard(board);
    printf("All queens placed successfully!\n");
    return 0;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                printf("|_");
            else
                printf("|♛");
        }
        printf("|\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col)
{
    // Check the row and column
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] || board[i][col])
            return 0;
    }

    // Check the diagonals
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + j == row + col || i - j == row - col)
            {
                if (board[i][j])
                    return 0;
            }
        }
    }

    return 1;
}

int placeQueen(int board[N][N], int row, int col)
{
    if (row >= 0 && row < N && col >= 0 && col < N && isSafe(board, row, col))
    {
        board[row][col] = 1;
        return 1;
    }
    return 0;
}
