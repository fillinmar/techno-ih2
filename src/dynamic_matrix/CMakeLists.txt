set(DYNAMIC_MATRIX matrix.c matrix.h)

add_library(dynamic_matrix SHARED ${DYNAMIC_MATRIX})

target_include_directories(dynamic_matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

