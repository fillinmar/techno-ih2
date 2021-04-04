
#include "matrix.h"
int main() {
    const char *file_name = "start_matrix.txt";
    const char *file_name_of_final_matrix = "mirror_matrix.txt";

    int vert = 5000;
    int hor = 10000;
    matrix *matrix = create_matrix(&hor, &vert);
    if (matrix == NULL)
        printf("Failed to allocate memory for smatrix..\n");

    if (make_file_start_matrix(*matrix, file_name) == 2)
        printf("Something went wrong with making file with matrix");

    if (read_and_fill_matrix(matrix, file_name) == 3)
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
