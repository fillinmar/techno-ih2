//
// Created by fillinmar on 25.03.2021.
//
#include <stdio.h>
#include "menu.h"

int create_menu() {
    const char *file_name = "start_matrix.txt";
    const char *file_name_of_final_matrix = "mirror_matrix.txt";

    int vert = 5;
    int hor = 10;
    Matrix *matrix = create_matrix(&hor, &vert);
    if (matrix == NULL)
        printf("Failed to allocate memory for static_matrix..\n");

    if (make_file_start_matrix(*matrix, file_name))
        printf("Something went wrong");

    read_and_fill_matrix(*matrix, file_name);

    if (make_mirror_matrix_with_file(matrix, file_name_of_final_matrix)) {
        printf("Something went wrong");
    }

    free_matrix(matrix);
    return 0;
}
