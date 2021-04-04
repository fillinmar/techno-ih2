//
// Created by fillinmar on 25.03.2021.
//
#include "matrix.h"
#include <stdlib.h>

#define ERROR_START_FILE 2
#define ERROR_OPEN_FILE 3
#define ERROR_MIRROR_FILE 4

int make_file_start_matrix(matrix matrix, const char *filename) {
    if (!filename)
        return ERROR_START_FILE;

    const char *mode = "w+";
    FILE *file;
    file = fopen(filename, mode);
    if (!file)
        return ERROR_START_FILE;

    for (int i = 0; i < matrix.horizontal * matrix.vertical; ++i) {
        fprintf(file, "%4d", rand() % 100);
    }

    if (fclose(file))
        return ERROR_START_FILE;

    return 0;
}

int make_file_with_mirror_matrix(matrix *matrix, const char *filename) {
    if (!filename)
        return ERROR_MIRROR_FILE;

    FILE *f = fopen(filename, "w+");

    if (!f)
        return ERROR_MIRROR_FILE;

    for (int i = 0; i < matrix->vertical; ++i) {
        for (int j = 0; j < matrix->horizontal; j++) {
            fprintf(f, "%4d ", matrix->array[i][j]);
        }
    }

    if (fclose(f))
        return ERROR_MIRROR_FILE;
    return 0;
}

int make_mirror_matrix_with_file(matrix *matrix, const char *filename) {
    int k = 2;
    for (int i = 0; i < matrix->vertical; ++i) {
        for (int j = 0; j < (matrix->horizontal - k); ++j) {
            swap(&matrix->array[i][j], &matrix->array[matrix->vertical - 1 - i][matrix->horizontal - j - 1]);
        }
        k = k + 2;
    }

    return (make_file_with_mirror_matrix(matrix, filename));
}

matrix *create_matrix(int *horizontal, int *vertical) {
    if (!horizontal || !vertical) {
        return NULL;
    }

    matrix *m = (matrix *) malloc(sizeof(matrix));
    if (!m)
        return NULL;

    m->horizontal = *horizontal;
    m->vertical = *vertical;
    m->array = (int **) malloc(m->vertical * sizeof(int *));
    if (!m->array)
        return NULL;

    for (int i = 0; i < m->vertical; i++) {
        m->array[i] = (int *) malloc(m->horizontal * sizeof(int));
        if (!m->array[i])
            return NULL;
    }
    return m;
}

int read_and_fill_matrix(matrix *matrix_to_generate, const char *filename) {
    int temp = 0;
    FILE *f = fopen(filename, "rt");
    if (!f)
        return ERROR_OPEN_FILE;
    for (int i = 0; i < matrix_to_generate->vertical; ++i) {
        for (int j = 0; j < matrix_to_generate->horizontal; ++j) {
            fscanf(f, "%d", &temp);
            matrix_to_generate->array[i][j] = temp;
        }
    }
    fclose(f);
}

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


void free_matrix(matrix *mart) {
    if (mart == NULL) {
        return;
    }

    if ((*mart).array == NULL) {
        free(mart);
        mart = NULL;
        return;
    }

    for (int i = 0; i < mart->vertical; i++) {
        free(mart->array[i]);
    }
    free(mart->array);
    free(mart);
    mart = NULL;
}

