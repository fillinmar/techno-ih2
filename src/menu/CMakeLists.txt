set(MENU_SRC menu.h menu.c)

add_library(menu STATIC ${MENU_SRC})

target_include_directories(menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(parallel_algorithm)
    target_link_libraries(menu PUBLIC parallel_matrix)
else()
    target_link_libraries(menu PUBLIC static_matrix)
endif(parallel_algorithm)
