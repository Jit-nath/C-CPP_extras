#include <stdlib.h>
#include <stdio.h>
#include "vectors.h"

vector2d *create_vector(int row_arg, int column_arg)
{
    vector2d *vec = malloc(sizeof(vector2d));
    if (vec == NULL)
        return NULL;

    vec->row = row_arg;
    vec->column = column_arg;

    vec->array = malloc(row_arg * sizeof(int *));
    if (vec->array == NULL)
    {
        free(vec);
        return NULL;
    }

    for (int i = 0; i < row_arg; i++)
    {
        vec->array[i] = malloc(column_arg * sizeof(int));
        if (vec->array[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(vec->array[j]);
            }
            free(vec->array);
            free(vec);
            return NULL;
        }
    }
    vec->position = -1;
    return vec;
}

void free_vector2d(vector2d *vec)
{
    if (vec == NULL)
        return;
    for (int i = 0; i < vec->row; i++)
    {
        free(vec->array[i]);
    }
    free(vec->array);
    free(vec);
}

void add_element_auto(int element, vector2d *vec)
{
    if (vec->position == -1)
    {
        vec->array[0][0] = element;
    }
    else if (vec->position > vec->row * vec->column)
    {
        printf("\nlist is full, increase list size.");
    }
    // TODO:  else{
    // add elements
    // }
}
void add_element_manual();
void delete_element_auto();
vector2d *add_2d();
vector2d *sub_2d();
vector2d zeros();
vector2d ones();
int main()
{
    return 0;
}
