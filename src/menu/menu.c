//
// Created by fillinmar on 25.03.2021.
//
#include <stdio.h>
#include "menu.h"

int create_menu() {
    const char *file_name = "start_matrix.txt";
    const char *file_name_of_final_matrix = "mirror_matrix.txt";

    int vert = 3;
    int hor = 6;
    Matrix *matrix = create_matrix(&hor, &vert);
    if (matrix == NULL)
        printf("Failed to allocate memory for smatrix..\n");

    if (make_file_start_matrix(*matrix, file_name) == 2)
        printf("Something went wrong with making file with matrix");

    if (read_and_fill_matrix(*matrix, file_name) == 3)
        printf("Something went wrong with open file with matrix");

    int result_of_funk = make_mirror_matrix_with_file(matrix, file_name_of_final_matrix);
    if (result_of_funk == 4)
        printf("Something went wrong with making file with mirror matrix");
    else if (result_of_funk == 6)
        printf("Failed to allocate memory during making mirror matrix..");
    else if (result_of_funk == 5)
        printf("Failed to map during making mirror matrix..");

    free_matrix(matrix);
    return 0;
}
