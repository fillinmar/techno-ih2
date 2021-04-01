//
// Created by fillinmar on 25.03.2021.
//
#include "matrix.h"
#include <stdlib.h>


void print_start_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.vertical; ++i) {
        for (int j = 0; j < matrix.horizontal; ++j)
            printf("%d ", matrix.array[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

void print_final_matrix(Matrix *matrix) {
    for (int i = 0; i < matrix->vertical; ++i) {
        for (int j = 0; j < matrix->horizontal; j++) {
            printf("%d ", matrix->array[i][j]);
        }
        printf("\n");
    }
}

int make_file_start_matrix(Matrix matrix, const char *filename) {
    //const char *filename = "static_matrix.txt";
    const char *mode = "w";

    FILE *file;
    file = fopen(filename, mode);
    if (!file) {
        fprintf(stderr, "Failed to open file for read\n");
        return 1;
    }
    for (int i = 0; i < matrix.horizontal * matrix.vertical; ++i) {
        fprintf(file, "%4d", rand() % 100);

    }
    if (fclose(file)) {
        fprintf(stderr, "Failed to close file\n");
        return 1;
    }
    return 0;
}

int make_file_with_mirror_matrix(Matrix *matrix, const char *filename) {

    FILE *f = fopen(filename, "wb");

    if (!f) {
        fprintf(stderr, "Failed to open file for write\n");
        return 1;
    }

    for (int i = 0; i < matrix->vertical; ++i) {
        for (int j = 0; j < matrix->horizontal; j++) {
            fprintf(f, "%4d ", matrix->array[i][j]);
        }
    }

    if (fclose(f)) {
        fprintf(stderr, "Failed to close file\n");
        return 1;
    }
    return 0;
}

int make_mirror_matrix_with_file(Matrix *matrix, const char *filename) {
    int k = 2;
    for (int i = 0; i < matrix->vertical; ++i) {
        for (int j = 0; j < (matrix->horizontal - k); ++j) {
            swap(&matrix->array[i][j], &matrix->array[matrix->vertical - 1 - i][matrix->horizontal - j - 1]);
        }
        k = k + 2;
    }

    if (make_file_with_mirror_matrix(matrix, filename))
        printf("error with file");
    return 0;
}

Matrix *create_matrix(int *horizontal, int *vertical) {
    if (!horizontal || !vertical) {
        return NULL;
    }

    Matrix *m = (Matrix *) malloc(sizeof(Matrix));
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

void read_and_fill_matrix(Matrix matrix_to_generate, const char *filename) {
    int temp = 0;
    FILE *f = fopen(filename, "rt");
    for (int i = 0; i < matrix_to_generate.vertical; ++i) {
        for (int j = 0; j < matrix_to_generate.horizontal; ++j) {
            fscanf(f, "%d", &temp);
            matrix_to_generate.array[i][j] = temp;
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


void free_matrix(Matrix *mart) {
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
