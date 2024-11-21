#include <stdio.h>

int main()
{
    int row = 3;
    int col = 3;
    int matrix3[row][col];

    int matrix1[][] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    int matrix2[][] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}