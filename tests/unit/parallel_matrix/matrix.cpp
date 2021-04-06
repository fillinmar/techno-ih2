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

    FILE *f1 = fopen(filename1, "r");
    FILE *f2 = fopen(filename2, "r");

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


TEST(INITIALIZE, CREATE_MATRIX) {
    matrix *test_matrix = create_matrix(&test1_hor, &test1_vert);
    EXPECT_TRUE(test_matrix != NULL);
    EXPECT_TRUE(test_matrix->array != NULL);

    free_matrix(test_matrix);
}

TEST(MATRIX, READ_AND_FILL) {
    matrix *test_matrix = create_matrix(&test1_hor, &test1_vert);
    EXPECT_TRUE(test_matrix != NULL);
    int temp = 0;
    FILE *f = fopen(test_filename, "rt");
    EXPECT_TRUE(f);

    for (int i = 0; i < test_matrix->vertical / 2 + (test_matrix->vertical % 2); ++i) {
        for (int j = 0; j < test_matrix->horizontal; ++j) {
            fscanf(f, "%d", &temp);
            test_matrix->array[i*test_matrix->horizontal+j] = temp;
        }
    }
    for (int i = test_matrix->vertical / 2 - 1; i >= 0; --i) {
        for (int j = test_matrix->horizontal; j < test_matrix->horizontal * 2; ++j) {
            fscanf(f, "%d", &temp);
            test_matrix->array[i*test_matrix->horizontal+j] = temp;
        }
    }
    fclose(f);
    matrix *test_matrix_check = create_matrix(&test1_hor, &test1_vert);
    EXPECT_TRUE(!read_and_fill_matrix(test_matrix_check, test_filename));
    for (int i = 0; i < test_matrix->vertical / 2 + (test_matrix->vertical % 2); ++i) {
        for (int j = 0; j < test_matrix->horizontal; ++j) {
            EXPECT_EQ(test_matrix->array[i*test_matrix->horizontal+j], test_matrix_check->array[i*test_matrix_check->horizontal+j]);
        }
    }
    for (int i = test_matrix->vertical / 2 - 1; i >= 0; --i) {
        for (int j = test_matrix->horizontal; j < test_matrix->horizontal * 2; ++j) {
            EXPECT_EQ(test_matrix->array[i*test_matrix->horizontal+j], test_matrix_check->array[i*test_matrix_check->horizontal+j]);
            fscanf(f, "%d", &temp);
        }
    }
    free_matrix(test_matrix);
    free_matrix(test_matrix_check);
}
TEST(MATRIX, MIRROR_PARALLEL_MATRIX_ALGOR
) {
    matrix *test_matrix = create_matrix(&test1_hor, &test1_vert);
    if (test_matrix == NULL)
        printf("Failed to allocate memory for static_matrix..\n");
    EXPECT_TRUE(!read_and_fill_matrix(test_matrix, test_filename));
    EXPECT_TRUE(!make_mirror_matrix_with_file(test_matrix, test_final_filename));
    free_matrix(test_matrix);

}
