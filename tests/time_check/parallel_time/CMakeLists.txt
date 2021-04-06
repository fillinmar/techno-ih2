
file(GLOB SRCS *.c)

project(time_check_parallel_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
        parallel_matrix
        )