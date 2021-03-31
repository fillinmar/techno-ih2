//
// Created by fillinmar on 29.03.2021.
//

#ifndef HW_2_MATRIX_H
#define HW_2_MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int **array;
    int vertical;
    int horizontal;
} Matrix;

Matrix *create_matrix(int *horizontal, int *vertical);

int make_file_start_matrix(Matrix matrix, const char *filename );

int read_and_fill_matrix(Matrix matrix, const char *filename);

void print_start_matrix(Matrix matrix);

//void swap(int *a, int *b);

int make_file_with_mirror_matrix(int *matrix, int horizontal, const char *filename);

void print_final_matrix(int *matrix, int horizontal);

int make_mirror_matrix_with_file(Matrix *matrix, const char *filename);


void free_matrix(Matrix *mart);

#endif //HW_2_MATRIX_H
