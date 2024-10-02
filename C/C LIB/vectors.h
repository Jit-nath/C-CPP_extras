#ifndef VECTORS_H
#define VECTORS_H

typedef struct
{
    int row;
    int column;
    int **array;
    int position;
} vector2d;

vector2d *create_vector(int row_arg, int column_arg);

void free_vector2d(vector2d *vec);

#endif