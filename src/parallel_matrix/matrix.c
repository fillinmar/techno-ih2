//
// Created by fillinmar on 29.03.2021.
//

#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

int make_mirror_matrix_with_file(Matrix *matrix, const char *filename) {
    if (!filename)
        return 4;
    int *index_of_diagonal = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                                  MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!index_of_diagonal) {
        return 5;
    }
    *index_of_diagonal = matrix->horizontal;

    int *count_of_passed = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!count_of_passed) {
        return 5;
    }
    *count_of_passed = 0;

    int size_of_martix = matrix->horizontal * matrix->vertical * sizeof(int);

    int *mirror_paral_matrix = mmap(NULL, size_of_martix, PROT_READ | PROT_WRITE,
                                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (!mirror_paral_matrix) {
        return 5;
    }

    int count_of_process = matrix->vertical / 2 + matrix->vertical % 2;
    int *pids = (int *) calloc(count_of_process, sizeof(int));
    if (!pids)
        return 6;

    for (int i = 0; i < count_of_process; ++i) {
        pids[i] = fork();
        if (pids[i] == -1) {
            printf("Fork failed\n");
            if (munmap(mirror_paral_matrix, size_of_martix))
                return 5;
        }
        if (pids[i] == 0) {
            child_procces_work(mirror_paral_matrix, matrix, count_of_process, i, count_of_passed, index_of_diagonal);
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < count_of_process; ++i) {
        int status;
        if (waitpid(pids[i], &status, 0) != pids[i] || WEXITSTATUS(status) != 0) {
            return 0;
        }
    }
//    printf("my matrix is");
//    print_final_matrix(mirror_paral_matrix, matrix->horizontal);

    free(pids);

    return (make_file_with_mirror_matrix(mirror_paral_matrix, matrix->horizontal, filename));
}

void child_procces_work(int *mirror_paral_matrix, Matrix *matrix, int count_of_process, int i, int *count_of_passed,
                        int *index_of_diagonal) {
    int middle_of_array = matrix->vertical / 2;
    if (matrix->vertical % 2 == 1 && i == count_of_process - 1) {
        for (int j = 0; j < matrix->horizontal / 2 - 1; ++j) {
            mirror_paral_matrix[middle_of_array * matrix->horizontal + j] = matrix->array[middle_of_array][
                    matrix->horizontal - j - 1];
            mirror_paral_matrix[matrix->horizontal * matrix->vertical - 1 - j -
                                *count_of_passed] = matrix->array[middle_of_array][j];;
        }
        mirror_paral_matrix[middle_of_array * matrix->horizontal + matrix->horizontal / 2 -
                            1] = matrix->array[middle_of_array][
                matrix->horizontal / 2 - 1];
        mirror_paral_matrix[middle_of_array * matrix->horizontal +
                            matrix->horizontal / 2] = matrix->array[middle_of_array][matrix->horizontal / 2];

    } else
        for (int j = 0; j < matrix->horizontal; ++j) {
            if (j < *index_of_diagonal - 2 || j >= *index_of_diagonal) {
                mirror_paral_matrix[(*count_of_passed) + j] = matrix->array[i][matrix->horizontal * 2 - j - 1];
                mirror_paral_matrix[matrix->horizontal * matrix->vertical - 1 - j -
                                    *count_of_passed] = matrix->array[i][j];
            } else {
                mirror_paral_matrix[(*count_of_passed) + j] = matrix->array[i][j];
                mirror_paral_matrix[matrix->horizontal * matrix->vertical - 1 - j -
                                    *count_of_passed] = matrix->array[i][
                        matrix->horizontal * 2 -
                        j -
                        1];
            }

        }
    *index_of_diagonal = *index_of_diagonal - 2;
    *count_of_passed = *count_of_passed + matrix->horizontal;
}

int make_file_with_mirror_matrix(int *matrix, int horizontal, const char *filename) {
    if (!filename)
        return 4;
    FILE *f = fopen(filename, "w+");
    if (!f)
        return 4;

    for (int i = 0; i < horizontal * horizontal * 0.5; ++i) {
        fprintf(f, "%4d", matrix[i]);
    }
    if (fclose(f))
        return 4;

    return 0;
}

void print_final_matrix(int *matrix, int horizontal) {
    for (int i = 0; i < horizontal * 0.5 * horizontal; ++i) {
        if (i % (horizontal) == 0)
            printf("\n");
        printf("%d ", matrix[i]);
    }
}

void print_start_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.vertical / 2 + matrix.vertical % 2; ++i) {
        for (int j = 0; j < matrix.horizontal; ++j)
            printf("%d ", matrix.array[i][j]);
        printf("\n");
    }
    for (int i = matrix.vertical / 2 - 1; i >= 0; --i) {
        for (int j = matrix.horizontal; j < matrix.horizontal * 2; ++j)
            printf("%d ", matrix.array[i][j]);
        printf("\n");
    }
    printf("\n\n");
}

int make_file_start_matrix(Matrix matrix, const char *filename) {
    if (!filename)
        return 2;
    const char *mode = "w+";

    FILE *file = fopen(filename, mode);
    if (!file)
        return 2;
    for (int i = 0; i < matrix.horizontal * matrix.vertical; ++i) {
        fprintf(file, "%4d", rand() % 100);
    }
    if (fclose(file)) {
        return 2;
    }
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
    m->array = (int **) malloc((m->vertical / 2 + m->vertical % 2) * sizeof(int *));
    if (!m->array)
        return NULL;

    for (int i = 0; i < m->vertical / 2 + m->vertical % 2; i++) {
        m->array[i] = (int *) malloc(m->horizontal * 2 * sizeof(int));
        if (!m->array[i])
            return NULL;
    }
    return m;
}

int read_and_fill_matrix(Matrix matrix, const char *filename) {
    int temp = 0;
    FILE *f = fopen(filename, "rt");
    if (!f)
        return 3;

    for (int i = 0; i < matrix.vertical / 2 + (matrix.vertical % 2); ++i) {
        for (int j = 0; j < matrix.horizontal; ++j) {
            fscanf(f, "%d", &temp);
            matrix.array[i][j] = temp;
        }
    }
    for (int i = matrix.vertical / 2 - 1; i >= 0; --i) {
        for (int j = matrix.horizontal; j < matrix.horizontal * 2; ++j) {
            fscanf(f, "%d", &temp);
            matrix.array[i][j] = temp;
        }
    }
    fclose(f);
    return 0;
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

    for (int i = 0; i < mart->vertical / 2 + mart->vertical % 2; i++) {
        free(mart->array[i]);
    }
    free(mart->array);
    free(mart);
    mart = NULL;
}
