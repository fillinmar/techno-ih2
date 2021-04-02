//
// Created by fillinmar on 01.04.2021.
//


#include <time.h>
#include "matrix.h"
#include <stdio.h>


const int test_count = 30;
int test_vert = 500;
int test_hor = 1000;

const char *test_filename = "test_matrix.txt";
const char *test_final_filename = "test_final_matrix.txt";

int main() {

    clock_t begin = clock();

    for (size_t i = 0; i < test_count; ++i) {

        Matrix *test_matrix = create_matrix(&test_hor, &test_vert);
        if (test_matrix == NULL)
            printf("Failed to allocate memory for static_matrix..\n");

        make_file_start_matrix(*test_matrix, test_filename);
        read_and_fill_matrix(*test_matrix, test_filename);

        make_mirror_matrix_with_file(test_matrix, test_final_filename);
        free_matrix(test_matrix);
    }
    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("\nTime to mirror parallel matrix in seconds: %f\n", time_spent);
    return 0;
}
