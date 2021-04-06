set(MATRIX_SRC matrix.h matrix.c)

add_library(static_matrix STATIC ${MATRIX_SRC})

target_include_directories(static_matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})