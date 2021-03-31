//
// Created by fillinmar on 31.03.2021.
//

#include <gtest/gtest.h>
#include <time.h>

extern "C" {
#include "matrix.h"
}

const int test_count = 5;
int test_vert = 100;
int test_hor = 200;

const char *test_filename = "test_matrix.txt";
const char *test_final_filename = "test_final_matrix.txt";

TEST(MATRIX, TIME_TO_MAKE) {

    clock_t begin = clock();

    for (size_t i = 0; i < test_count; ++i) {

        Matrix *test_matrix = create_matrix(&test_hor, &test_vert);
        if (test_matrix == NULL)
            printf("Failed to allocate memory for static_matrix..\n");
        EXPECT_TRUE(!make_file_start_matrix(*test_matrix, test_filename));
        read_and_fill_matrix(*test_matrix, test_filename);
        EXPECT_TRUE(!make_mirror_matrix_with_file(test_matrix, test_final_filename));
        free_matrix(test_matrix);
    }
    clock_t end = clock();

    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    std::cout << "Time to mirror matrix in seconds" << time_spent << std::endl;
}