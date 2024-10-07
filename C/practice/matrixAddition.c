#include <stdio.h>
#define SIZE_I 3
#define SIZE_J 3
int main()
{
    int matrix1[SIZE_I][SIZE_J], matrix2[SIZE_I][SIZE_J];
    int result_matrix[SIZE_I][SIZE_J];

    printf("Enter the values of matrix 1->");
    for (int i = 0; i < SIZE_I; i++)
    {
        for (int j = 0; j < SIZE_J; j++)
        {
            printf("\npos(%d,%d)->", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the values of matrix 2->");
    for (int i = 0; i < SIZE_I; i++)
    {
        for (int j = 0; j < SIZE_J; j++)
        {
            printf("\npos(%d,%d)->", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // matrix addition
    for (int i = 0; i < SIZE_I; i++)
    {
        for (int j = 0; j < SIZE_J; j++)
        {
            result_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Result matrix->\n");
    for (int i = 0; i < SIZE_I; i++)
    {
        for (int j = 0; j < SIZE_J; j++)
        {
            printf("%d\t", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}