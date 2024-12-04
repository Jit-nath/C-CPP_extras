#include <stdio.h>
#include <stdlib.h>

int main() {
    int row = 3, col = 3;
    int matrix1[row][col], matrix2[row][col];
    int result_matrix[row][col];

    // check if possible

    if (col != row) {
        printf("\n Matrix MUltiplication is not possible");
        exit(0);
    }

    printf("\nEnter the values of matrix 1->");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("\npos(%d,%d)->", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the values of matrix 2->");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("\npos(%d,%d)->", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // matrix
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result_matrix[i][j] = 0;
            for (int k = 0; k < col; k++) {
                result_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("Result matrix->\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}