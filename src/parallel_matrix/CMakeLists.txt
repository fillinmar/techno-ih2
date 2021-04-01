set(PARALLEL_MATRIX matrix.c matrix.h)

add_library(parallel_matrix SHARED ${PARALLEL_MATRIX})

target_include_directories(parallel_matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

