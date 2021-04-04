//
// Created by fillinmar on 25.03.2021.
//

#ifndef HW_2_MATRIX_H
#define HW_2_MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int **array;
    int horizontal;
    int vertical;
} matrix;

matrix *create_matrix(int *horizontal, int *vertical);

int make_file_start_matrix(matrix matrix, const char *filename);

int read_and_fill_matrix(matrix *matrix_to_generate, const char *filename);

void swap(int *a, int *b);

int make_mirror_matrix_with_file(matrix *matrix, const char *filename);

int make_file_with_mirror_matrix(matrix *matrix, const char *filename);

void free_matrix(matrix *mart);

#endif //HW_2_MATRIX_H
