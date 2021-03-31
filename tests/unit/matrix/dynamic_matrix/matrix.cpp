//
// Created by fillinmar on 31.03.2021.
//
#include <gtest/gtest.h>
#include <fstream>

extern "C" {
#include "matrix.h"
}

// char *open_params = "r";
const char *test_filename = "file_with_matrix/test_matrix.txt";
const char *test_final_filename = "file_with_matrix/test_final_matrix.txt";
const char *test_expect_filename = "file_with_matrix/test_expect_matrix.txt";


int test1_vert = 2;
int test1_hor = 4;

bool compareFiles(const std::string& p1, const std::string& p2) {
    std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
    std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

    if (f1.fail() || f2.fail()) {
        return false; //file problem
    }

    if (f1.tellg() != f2.tellg()) {
        return false; //size mismatch
    }

    //seek back to beginning and use std::equal to compare contents
    f1.seekg(0, std::ifstream::beg);
    f2.seekg(0, std::ifstream::beg);
    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

TEST(MATRIX, MIRROR_DYNAMIC_SMALL_MATRIX
)
{
FILE *source_file = fopen(test_filename, "wb");
EXPECT_TRUE(source_file);

Matrix *test_matrix = create_matrix(&test1_hor, &test1_vert);
if (test_matrix == NULL)
printf("Failed to allocate memory for static_matrix..\n");

//make_file_start_matrix(*matrix);
read_and_fill_matrix(*test_matrix, test_filename);
//print_start_matrix(*static_matrix);
EXPECT_FALSE(make_mirror_matrix_with_file(test_matrix, test_final_filename));
EXPECT_TRUE(compareFiles(test_final_filename,test_expect_filename));
free_matrix(test_matrix);

//std::ifstream t(test_filename);
//std::string genfile((std::istreambuf_iterator<char>(t)),
//                    std::istreambuf_iterator<char>());
//
//std::ifstream want (test_expect_filename);
//std::string expectedOutput = ((std::istreambuf_iterator<char>(got)),
//        std::istreambuf_iterator<char>());
//
//ASSERT_EQ(expectedOutput,genfile);


printf("\n");

}

//TEST(MATRIX, MIRROR_DYNAMIC_NOT_SO_SMALL_MATRIX
//)
//{
//Total *res = collect_size(nullptr, point_counter);
//EXPECT_TRUE(!res);
//}
