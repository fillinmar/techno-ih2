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
} Matrix;

Matrix *create_matrix(int *horizontal, int *vertical);

int make_file_start_matrix(Matrix matrix, const char *filename);

void read_and_fill_matrix(Matrix matrix_to_generate, const char *filename);

void swap(int *a, int *b);

void print_start_matrix(Matrix matrix);

void print_final_matrix(Matrix *matrix);

int make_mirror_matrix_with_file(Matrix *matrix, const char *filename);

int make_file_with_mirror_matrix(Matrix *matrix, const char *filename);

void free_matrix(Matrix *mart);

#endif //HW_2_MATRIX_H
