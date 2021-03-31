file(GLOB SRCS *.cpp)

project(dynamic_matrix_test_correct)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        dynamic_matrix
        gtest
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})

#configure_file(file_with_matrix/test_matrix.txt file_with_matrix/test_matrix.txt COPYONLY)
#configure_file(file_with_matrix/test_final_matrix.txt file_with_matrix/test_final_matrix.txt COPYONLY)
#configure_file(file_with_matrix/test_expect_matrix.txt file_with_matrix/test_expect_matrix.txt COPYONLY)