//
// Created by fillinmar on 31.03.2021.
//

#include <gtest/gtest.h>
#include <fstream>

extern "C" {
#include "matrix.h"
}

const char *test_filename = "file_with_matrix/test_matrix.txt";
const char *test_final_filename = "file_with_matrix/test_final_matrix.txt";
const char *test_expect_filename = "file_with_matrix/test_expect_matrix.txt";

int test1_vert = 5;
int test1_hor = 10;

bool compareFiles(const char *filename1, const char *filename2) {
    int ch1 = 0, ch2 = 0;

    FILE *f1 = fopen(filename2, "r");
    FILE *f2 = fopen(filename1, "r");

    while (!feof(f1) && !feof(f2) && (ch1 == ch2)) {
        fscanf(f1, "%d", &ch1);
        fscanf(f2, "%d", &ch2);
    }

    fclose(f2);
    fclose(f1);

    if (ch1 == ch2) {
        return true;
    } else {
        return false;
    }
}

TEST(MATRIX, MIRROR_PARALLEL_MATRIX
) {
    Matrix *test_matrix = create_matrix(&test1_hor, &test1_vert);
    if (test_matrix == NULL)
        printf("Failed to allocate memory for static_matrix..\n");
    read_and_fill_matrix(*test_matrix, test_filename);
    EXPECT_TRUE(!make_mirror_matrix_with_file(test_matrix, test_final_filename));
    EXPECT_TRUE(compareFiles(test_final_filename, test_expect_filename));
    free_matrix(test_matrix);
    printf("\n");

}