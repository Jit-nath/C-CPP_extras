#include <stdio.h>
#include <stdlib.h>
#define R1 3
#define C1 3
#define R2 3
#define C2 3
#define R3 3
#define C3 3
int main()
{
    int matrix1[R1][C1], matrix2[R2][C2];
    int result_matrix[R3][C3];

    // check if possible

    if (C1 != R2)
    {
        printf("\n Matrix MUltiplication is not possible");
        exit(0);
    }

    printf("\nEnter the values of matrix 1->");
    for (int i = 0; i < R1; i++)
    {
        for (int j = 0; j < C1; j++)
        {
            printf("\npos(%d,%d)->", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the values of matrix 2->");
    for (int i = 0; i < R2; i++)
    {
        for (int j = 0; j < C2; j++)
        {
            printf("\npos(%d,%d)->", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // matrix
    for (int i = 0; i < R3; i++)
    {
        for (int j = 0; j < C3; j++)
        {
            result_matrix[i][j] = 0;
            for (int k = 0; k < C3; k++)
            {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Result matrix->\n");
    for (int i = 0; i < R3; i++)
    {
        for (int j = 0; j < C3; j++)
        {
            printf("%d\t", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}