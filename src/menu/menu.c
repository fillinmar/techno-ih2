//
// Created by fillinmar on 25.03.2021.
//
#include <stdio.h>
#include "menu.h"
#include <time.h>


int create_menu() {
    const char *file_name = "start_matrix.txt";
    const char *file_name_of_final_matrix = "mirror_matrix.txt";
    clock_t begin = clock();

    int vert = 500;
    int hor = 1000;
    Matrix *matrix = create_matrix(&hor, &vert);
    if (matrix == NULL)
        printf("Failed to allocate memory for static_matrix..\n");

    make_file_start_matrix(*matrix, file_name);
    read_and_fill_matrix(*matrix, file_name);
    //print_start_matrix(*matrix);

    if (make_mirror_matrix_with_file(matrix, file_name_of_final_matrix)) {
        printf("error with procceses");
    }

    free_matrix(matrix);

    printf("\n");
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Time to mirror matrix in  %f seconds.\n", time_spent);
    return 0;
}