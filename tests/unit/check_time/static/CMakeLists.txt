file(GLOB SRCS *.cpp)

project(static_matrix_test)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PUBLIC
        static_matrix
        ${GTEST_LIBRARIES} Threads::Threads
        )

add_test(NAME ${PROJECT_NAME}
        COMMAND ${PROJECT_NAME})