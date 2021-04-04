set(MAIN_SRCS main.c)

add_executable(main ${MAIN_SRCS})

target_link_libraries(main PRIVATE menu)

install(TARGETS main DESTINATION bin)

if(parallel_algorithm)
    target_link_libraries(main PUBLIC parallel_matrix)
else()
    target_link_libraries(main PUBLIC static_matrix)
endif(parallel_algorithm)