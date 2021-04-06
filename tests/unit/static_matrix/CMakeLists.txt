file(GLOB SRCS *.cpp)

project(static_matrix_test_correct)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
        static_matrix
        ${GTEST_LIBRARIES} Threads::Threads
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})


configure_file(file_with_matrix/test_matrix.txt file_with_matrix/test_matrix.txt COPYONLY)
configure_file(file_with_matrix/test_expect_matrix.txt file_with_matrix/test_expect_matrix.txt COPYONLY)