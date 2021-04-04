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
} matrix;

matrix *create_matrix(int *horizontal, int *vertical);

int make_file_start_matrix(matrix matrix, const char *filename);

int read_and_fill_matrix(matrix *matrix, const char *filename);

int make_file_with_mirror_matrix(int *matrix, int horizontal, const char *filename);

int make_mirror_matrix_with_file(matrix *matrix, const char *filename);

void procces_work(int*mirror_paral_matrix, matrix *matrix, int count_of_process, int i, int *count_of_passed, int *index_of_diagonal);

void free_matrix(matrix *mart);

#endif //HW_2_MATRIX_H
